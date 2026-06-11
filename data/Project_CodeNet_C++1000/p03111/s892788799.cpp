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

ll n,A,B,C;
ll l[8];

ll dfs(ll cur, ll a, ll b, ll c){
    if(cur==n){
        return min({a,b,c})>0 ? abs(a-A)+abs(b-B)+abs(c-C)-30 : inf;
    }
    ll ret0 = dfs(cur+1, a,b,c);
    ll ret1 = dfs(cur+1, a+l[cur],b,c) + 10;
    ll ret2 = dfs(cur+1, a,b+l[cur],c) + 10;
    ll ret3 = dfs(cur+1, a,b,c+l[cur]) + 10;
    return min({ret0, ret1, ret2, ret3});
}

int main(){FIN

    cin>>n>>A>>B>>C;
    REP(i,n) cin>>l[i];
    ll ans = dfs(0,0,0,0);
    cout<<ans<<endl;
    return 0;
}