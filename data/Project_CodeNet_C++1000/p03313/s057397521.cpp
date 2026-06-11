#include    <bits/stdc++.h>
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
#define fd(i,a,b) for(int i=(a);i>=(b);--i)
#define rep(i,a,b)  for(int i=(a);i<(b);++i)
#define fi  first
#define se  second
#define LL  unsigned long long
#define uint unsigned int
#define pb  push_back
#define eb  emplace_back
#define bit(s,i) ((s >> i) & 1)
#define off(s,i) (s & (~ (1 << i)))
#define ii pair <int , int>
#define iii1 pair <ii , int>
#define iii2 pair <int , ii>
#define TASK "Or Plus Max"
using   namespace   std;
const long long inf = 0x3f3f3f3f3f3f3f3f;
const int oo = 0x3f;
int n , a[270010] , res[270010];
ii f[270010];
///--------------------------
void readf() {
    cin >> n;
    for (int i = 0 ; i < (1 << n) ; ++i) cin >> a[i];
}
///--------------------------
void solve() {
    for (int i = 0 ; i < (1 << n) ; ++i) {
        f[i].fi = a[i];
        f[i].se = 0;
    }
    for (int j = 0 ; j < n ; ++j)
    for (int i = 1 ; i < (1 << n) ; ++i)
    if (i != off(i,j)) {
        if (f[i].fi < f[off(i,j)].fi) {
            f[i].se = max({f[i].se , f[i].fi , f[off(i,j)].se});
            f[i].fi = f[off(i,j)].fi;
        } else f[i].se = max(f[i].se , f[off(i,j)].fi);
    }
    for (int i = 1 ; i < (1 << n) ; ++i) res[i] = max(res[i-1] , f[i].fi + f[i].se);
    for (int i = 1 ; i < (1 << n) ; ++i) cout << res[i] << '\n';
}
///--------------------------
int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);cout.tie(0);
   readf();
   solve();
}

