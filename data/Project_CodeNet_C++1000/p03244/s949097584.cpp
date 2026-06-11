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

    ll n;cin>>n;
    vll a(n); REP(i,n) cin>>a[i];
    map<ll,ll> m1,m2;
    REP(i,n){

        if(i%2==0) m1[a[i]]++;
        else m2[a[i]]++;
    }
    vector<P> v1,v2;
    for(auto p: m1) v1.push_back(make_pair(p.second, p.first));
    for(auto p: m2) v2.push_back(make_pair(p.second, p.first));
    VSORTR(v1); VSORTR(v2);
    if(v1[0].second != v2[0].second){
        ll ans = n - v1[0].first - v2[0].first;
        cout<<ans<<endl;
        return 0;
    }
    ll ans1 = inf, ans2 = inf;

    if(v1.size()>1) ans1 = n - v1[1].first - v2[0].first;
    if(v2.size()>1) ans2 = n - v1[0].first - v2[1].first;
    if (ans1==inf && ans2 == inf) {cout<<n/2<<endl; return 0;}
    cout<<min(ans1,ans2)<<endl;

    return 0;
}