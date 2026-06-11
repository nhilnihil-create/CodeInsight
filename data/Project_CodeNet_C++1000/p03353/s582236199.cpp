#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int k;
    cin >> k;

    set<string> st;

    int sub = min(k, (int)s.size());
    for (int i = 1; i <= sub; i++) {
        for (int j = 0; j < s.size() - i + 1; j++) {
            st.insert(s.substr(j, i));
        }
    }

    auto itr = st.begin();
    rep(i, k - 1) itr++;
    cout << *itr << endl;
}