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
    ll cnt = 0;
    rep(p, n/r+1){
        rep(q, n/g+1){
            if (r * p + g * q <= n && (n - r * p - g * q)%b == 0) cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
