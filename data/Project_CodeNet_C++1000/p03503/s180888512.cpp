#include <bits/stdc++.h>
#define REP(i, n) for(long long i=0; i<n; i++)
#define REPR(i, n) for(long long i=n-1; i>=0; i--)
#define FOR(i, m, n) for(long long i=m; i<=n; i++)
#define FORR(i, m, n) for(long long i=m; i>=n; i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define VSORTR(v) sort(v.rbegin(), v.rend());
#define ALL(v) (v).begin(),(v).end()
#define FIN ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;
using ll = long long;
using ull = unsigned long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;
const ll mod = 1e9+7;
const ll inf = 1e15;
ll power(ll a,ll b){return b?power(a*a%mod,b/2)*(b%2?a:1)%mod:1;}

ll f[105][10];
ll p[105][10];
int main(){FIN
    ll n;cin>>n;
    REP(i,n) REP(j,10){
        cin >> f[i][j];
    }
    REP(i,n) REP(j,11){
        cin>>p[i][j];
    }
    ll ans= (-1) * inf;
    for(ll i=1; i<(1<<10);i++){
        ll val=0;
        REP(j,n){
            ll cnt=0;
            REP(k,10){
                if ((i>>k)&1 && f[j][k]) cnt++;
            }
            val += p[j][cnt];
        }
        ans = max(ans, val);
    }
    cout<<ans<<endl;
    return 0;
}