#include<bits/stdc++.h>
using namespace std; 
  
typedef long long ll; 
typedef pair<ll, ll> pll;
typedef vector<ll> vl; 
typedef vector<vl> vvl; 
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);srand(time(NULL));
#define MOD 1000000007  
#define FOR(a, b, c) for (ll(a) = (b); (a) < (c); ++(a)) 
#define FORN(a, b, c) for (ll(a) = (b); (a) <= (c); ++(a)) 

#define REP(i, n) FOR(i, 0, n) 
#define REPN(i, n) FORN(i, 1, n) 
#define fi first 
#define se second 
#define mp make_pair 
#define pb push_back 
#define ALL(v) v.begin(), v.end() 
#define ALLA(arr, sz) arr, arr + sz 
#define SIZE(v) (int)v.size() 
#define SORT(v) sort(ALL(v)) 
#define REVERSE(v) reverse(ALL(v)) 
#define SORTA(arr, sz) sort(ALLA(arr, sz)) 
#define REVERSEA(arr, sz) reverse(ALLA(arr, sz)) 
#define TC(t) while (t--) 

int main()
{
    fast;
    ll i,j,k,m,n,q,r,c,x;
    cin>>i>>j>>k>>r>>c;
    ll ans=0;
    if((i+j) >= 2*k){
        x = min(r,c);
        ans += x*2*k; r -= x; c -= x;
    }
    if(r){
        if(r*i >= 2*k*r){
            ans += 2*k*r;
        }
        else
            ans += r*i;
    }
    if(c){
        if(c*j >= 2*k*c){
            ans += 2*k*c;
        }
        else
            ans += c*j;
    }
    cout<<ans;
}	