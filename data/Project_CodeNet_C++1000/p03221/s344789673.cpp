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



int main(){FIN

    ll n,m; cin>>n>>m;
    vector<P> ans(m);
    vector<vector<P>> v(n); 
    REP(i,m){
        ll a,b;cin>>a>>b;
        v[a-1].push_back(make_pair(b,i));
    }
    REP(i,n) VSORT(v[i]);
    REP(i,n){
        REP(j, v[i].size()){

            ans[v[i][j].second] = make_pair(i+1,j+1) ;
        }
    }
    REP(i,m){
        cout<<setfill('0') << setw(6) << ans[i].first<<setfill('0') << setw(6)<<ans[i].second<<endl;
    }

    return 0;
}