#include <bits/stdc++.h>
#define REP(i, n) for(long long i = 0; i < n; i++)
#define REPR(i, n) for(long long i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(long long i = m; i <= n; i++)
#define FORR(i, m, n) for(long long i = m; i >= n; i--)
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



int main(){FIN

    ll x,y,z,k; cin>>x>>y>>z>>k;
    vll a(x), b(y), c(z);
    REP(i,x) cin>>a[i]; REP(i,y) cin>>b[i]; REP(i,z) cin>>c[i];
    VSORTR(a); VSORTR(b); VSORTR(c);
    vll d(0);
    REP(i,x){
        REP(j,y){
            d.push_back(a[i]+b[j]);
        }
    }
    VSORTR(d);
    vll e(0);
    ll mx_idx = min(ll(d.size()), k); 
    REP(i,mx_idx){
        REP(j,z){
            e.push_back(d[i]+c[j]);
        }
    }
    VSORTR(e);
    REP(i,k) cout<<e[i]<<endl;
    return 0;
}