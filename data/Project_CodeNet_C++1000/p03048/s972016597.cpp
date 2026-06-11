#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;


int main(){
    ll r, g, b, n;
    cin >> r >> g >> b >> n;
    ll ans = 0;
    rep(i, 3001) rep(j, 3001){
        if(i*r + j*g <= n && (n - (i*r + j*g))%b == 0) ans++;
    }
    cout << ans << endl;
    return 0;
}
