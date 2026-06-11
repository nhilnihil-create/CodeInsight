#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define nl '\n'
#define f(i, n) for (int i = 0; i < n; ++i)

using namespace std;
void solve() {
    string s;
    cin >> s;
    for (int i = 0; i < (int)s.size(); ++i) {
        if (s[i] == '1') {
            s[i] = '9';
        } else if (s[i] == '9') {
            s[i] = '1';
        }
    }
    cout << s << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}