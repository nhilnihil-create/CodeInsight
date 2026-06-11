#include <bits/stdc++.h>
#define loop2(i, s, n, a) for (int i = int(s); i < int(n); i += a)
#define loop(i, s, n) loop2(i, s, n, 1)
#define rep(i, n) loop(i, 0, n)

#define pb push_back
#define all(in) in.begin(),in.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;

int main(){
    int n; cin >> n;
    ll f[n][10]; rep(i,n) rep(j,10) cin >> f[i][j];
    ll p[n][11]; rep(i,n) rep(j,11) cin >> p[i][j];

    ll ans = -(1ll<<60);
    loop(i,1,1<<10){
        ll data[n]; rep(j,n) data[j] = 0;
        rep(j,10){
            if(i & 1<<j){
                rep(k,n) if(f[k][j] == 1) data[k]++;
            }
        }
        ll count = 0;
        rep(j,n) count += p[j][data[j]];
        if(ans < count) ans = count;
    }
    
    cout << ans << endl;
}