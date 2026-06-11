#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;
typedef pair<int, int> P;

const ll mod =  1000000007;  //ansを出力する時は (ans % mod + mod) % mod とする(負の剰余を正にする)
const int inf = 1e9;
const long long INF = 1LL << 60;   // INFの値は1152921504606846976

int main()
{
    ll n; cin >> n;
    ll x[n],y[n],h[n];
    ll ans_h = 0;
    rep(i,n) cin >> x[i] >> y[i] >> h[i];
    rep(i,101){
        rep(j,101){
            ll ans = 0;
            rep(k,n){
                if(h[k] > 0) ans = h[k] + abs(x[k] - i) + abs(y[k] - j);
            }
            bool ok = true;
            rep(k,n){
                if(h[k] != max((ll)0,ans - abs(x[k] - i) - abs(y[k] - j))){
                    ok = false;
                }
            }
            if(ok){
                cout << i << ' ' << j << ' ' << ans << endl;
                return 0; 
            }
        }
    }
}