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

    ll n,k;cin>>n>>k;
    vll x(n); REP(i,n) cin>>x[i];
    ll ans =inf;
    for(ll i=0; i+k-1<n; i++){
        ll s = x[i];
        ll g = x[i+k-1];
        ll dis=0;
        if (s>=0) dis=g;
        else if(g<=0) dis=-s;
        else dis = g-s+min(g,-s);
        ans = min(ans,dis); 
        if (s>=0) break;
    }   
    cout<<ans<<endl;
    return 0;
}