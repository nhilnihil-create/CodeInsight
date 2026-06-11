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

ll a,b;

int main(){FIN

    ll n,m;cin>>n>>m;
    vector<P> v;
    REP(i,m){
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }
    VSORT(v);
    ll start = v[0].first;
    ll end = v[0].second;
    ll ans = 1;
    FOR(i,1,m-1){
        a=v[i].first;
        b=v[i].second;
        if (a>=end){
            ans++;
            start = a;
            end=b;
        }
        else{
            start=a;
            end=min(b,end);
        }
        // cout<<start<<end<<endl;
    }
    cout<<ans<<endl;
    return 0;
}