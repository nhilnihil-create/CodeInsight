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


ll a[305][305];

int main(){FIN

    ll h,w,d;cin>>h>>w>>d;
    vector<pair<ll,ll>> v(h*w+1);
    REP(i,h) REP(j,w) {
        cin>>a[i][j];
        v[a[i][j]] = make_pair(i,j);
    }

    vll ans(h*w+1,0);
    REP(i,d){
        ll start = i+1;
        while(start+d<=h*w){
            ans[start+d] = ans[start] + abs(v[start].first-v[start+d].first) + abs(v[start].second-v[start+d].second);
            start+=d;
        }
    }
    ll q;cin>>q;

    REP(i,q){
        ll l,r;cin>>l>>r;
        cout<<ans[r]-ans[l]<<endl;
    }
    return 0;
}