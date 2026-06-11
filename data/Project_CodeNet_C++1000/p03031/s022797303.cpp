#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

// int main() {
//     int n, m;
//     cin >> n >> m;
//     vector<int> a(n);
//     rep(i,m) {
//         int k;
//         cin >> k;
//         rep(j,k) {
//             int s;
//             cin >> s;
//             s--;
//             a[s] |= 1<<i;
//         }
//     }
//     int p = 0;
//     rep(i,m) {
//         int x;
//         cin >> x;
//         p |= x<<i;
//     }
//     int ans = 0;
//     rep(s,1<<n) {
//         int t = 0;
//         rep(i,n) {
//             if (s>>i&1) t ^= a[i];
//         }
//         if (t==p) ans++;
//     }
//     cout << ans << endl;
//     return 0;
// }

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> s(n);
    rep(i,m) {
        s[i] = 0;
        int c;
        cin >> c;
        rep(j,c){
            int t;
            cin >> t;
            s[i] |= 1<<(t-1);
        }
    }
    int p = 0;
    rep(i,m) {
        int t;
        cin >> t;
        p |= t<<i;
    }
    int ans = 0;
    rep(i,1<<n) {
        bool ok = true;
        rep(j,m) {
            if (__builtin_popcount(s[j]&i)%2 != (p>>j&1)) ok = false;
        }
        if (ok) ans++;
    }
    cout << ans << endl;
    return 0;
}
