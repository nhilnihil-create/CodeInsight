#include <bits/stdc++.h>
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
        for (int j = 0; i + j <= N - 1 && j <= K; ++j) {
            S += s[i + j];
            st.insert(S);
        }
    }
    auto itr = st.begin();
    while (--K)
        ++itr;
    cout << *itr << endl;
}