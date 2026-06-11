#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main() {
    string s;
    cin >> s;
    int N = s.size();
    int K;
    cin >> K;
    set<string> st;

    for (int i = 0; i <= N - 1; ++i) {
        string S = "";
        for (int j = 0; i + j <= N - 1&&j<=K; ++j) {
            S += s[i + j];
            st.insert(S);
        }
    }
    int now = 1;
    for (auto e : st) {
        if (now == K) {
            cout << e << endl;
            return 0;
        } else
            ++now;
    }
}