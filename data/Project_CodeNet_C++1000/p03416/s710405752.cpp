#include "bits/stdc++.h"

using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
#define lin "\n"
#define fast_io ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(0)
int a[105], b[105], c[105];

void solve() {
    int m, n;
    cin >> m >> n;
    ll cnt = 0;
    for (int i = m; i <= n; ++i) {
        string s = to_string(i);
        bool ok = true;
        for (int j = 0; j < s.size() / 2; ++j) {
            if (s[j] != s[s.size() - j - 1]) {
                ok = false;
                break;
            }
        }
        if (ok)
            cnt++;
    }
    cout << cnt << lin;
}

int main() {
    fast_io;
    int t = 1;
//    cin >> t;
    int c = 1;
    while (t--) {
//        printf("Case %lld: ",c);
//        cout<<"Case "<<c<<": ";
        solve();
        c++;
    }
}