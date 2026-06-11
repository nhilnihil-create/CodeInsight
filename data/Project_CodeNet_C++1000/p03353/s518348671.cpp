#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T>
using vec = std::vector<T>;

int main() {
    string s;
    cin >> s;
    int N = s.size();
    int K;
    cin >> K;
    set<string> st;

    for (int i = 0; i <= N - 1; ++i) {
        string S = "";
        S += s[i];
        st.insert(S);
        if (i <= N - 2) {
            S += s[i + 1];
            st.insert(S);
        }
        if (i <= N - 3) {
            S += s[i + 2];
            st.insert(S);
        }
        if (i <= N - 4) {
            S += s[i + 3];
            st.insert(S);
        }
        if (i <= N - 5) {
            S += s[i + 4];
            st.insert(S);
        }
    }
    int now = 1;
    for(auto e:st){
        if(now == K) {
            cout << e << endl;
            return 0;
        }
        else ++now;
    }
}