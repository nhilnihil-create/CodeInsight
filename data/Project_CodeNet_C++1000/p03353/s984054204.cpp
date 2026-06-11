#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;

string s;
ll K;

int main() {
    cin >> s >> K;

    // set<string> st = {"b", "abc", "a", "ba"};
    // for (auto iter = st.begin(); iter != st.end(); iter++) {
    // }

    set<string> st;
    for (ll k = 1; k <= 5; k++) {
        if (s.size() < k) break;
        for (ll i = 0; i <= s.size() - k; i++) {
            st.insert(s.substr(i, k));
        }
    }

    ll ans_idx = 0;
    for (auto iter = st.begin(); iter != st.end(); iter++) {
        if (ans_idx == K - 1) {
            cout << *iter << endl;
            break;
        }
        ans_idx++;
    }
}