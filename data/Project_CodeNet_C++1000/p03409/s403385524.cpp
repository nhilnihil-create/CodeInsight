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


char a[55][55];

int main(){FIN

    vector<P> a, b;
    ll n;cin>>n;
    REP(i,n){
        ll x,y; cin>>x>>y;
        a.push_back(make_pair(y,x));
    }
    REP(i,n){
        ll x,y; cin>>x>>y;
        b.push_back(make_pair(x,y));
    }
    VSORTR(a); VSORT(b);
    ll ans=0;
    vll b_mark(n,0);
    vll a_mark(n,0);
    REP(i,n){
        REP(j,n){
            if(b[i].second > a[j].first && b[i].first > a[j].second && b_mark[i]==0 && a_mark[j]==0){
                b_mark[i]=1;
                a_mark[j]=1;
                ans++;
                continue;
            }
        }

    }
    cout<<ans<<endl;
    return 0;
}