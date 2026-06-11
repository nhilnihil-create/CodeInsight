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
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;
const ll mod = 1e9+7;
const ll inf = 1e15;


ll power(ll a,ll b){return b?power(a*a%mod,b/2)*(b%2?a:1)%mod:1;}


int main(){FIN

    ll n, m;
    cin>>n>>m;
    vll x(n), y(n), z(n);
    REP(i,n) cin>>x[i]>>y[i]>>z[i];
    ll ans =0;
    for(ll i=0; i<(1<<3); i++){
        vll pm(3,1);
        REP(j,3) if(1&(i>>j)) pm[j]=-1;

        vll w(n);
        REP(i,n) w[i] = pm[0]*x[i] + pm[1]*y[i] + pm[2]*z[i];
        VSORTR(w);
        ll sum =0;
        REP(i,m) sum+=w[i];
        ans = max(ans, sum);
    }
    cout<<ans<<endl;
    return 0;
}