#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

typedef long long ll;
typedef pair<ll, ll> P;

const ll mod =  1000000007;  //出力は (ans % mod + mod) % mod  (負の剰余を正にする)
const int inf = 1e9;
const long long INF = 1LL << 60;   // INF = 1152921504606846976

int main()
{
    int n,m; cin >> n >> m;
    ll x[n],y[n],z[n];
    rep(i,n) cin >> x[i] >> y[i] >> z[i];
    ll ans = 0;
    for(int bit = 0; bit < (1<<3); bit++){
        vector<ll> v;
        rep(i,n){
            ll tmp = 0;
            if(bit & (1<<2)) tmp += x[i];
            else tmp -= x[i];
            if(bit & (1<<1)) tmp += y[i];
            else tmp -= y[i];
            if(bit & (1<<0)) tmp += z[i];
            else tmp -= z[i];
            v.push_back(tmp);
        }
        sort(all(v));
        reverse(all(v));
        ll tmp = 0;
        for(int i = 0; i < m; i++){
            tmp += v[i];
        }
        ans = max(ans,tmp);
    }
    cout << ans << endl;
}