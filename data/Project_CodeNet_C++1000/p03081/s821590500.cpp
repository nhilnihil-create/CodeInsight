#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define ld long double
#define FOR(i,a,n) for (int i=(a);i<=(n);++i)
#define RFOR(i,a,n) for (int i=(n);i>=(a);--i)
#define FI(i,n) for (int i=0; i<(n); ++i)
#define ZERO(a) memset((a),0,sizeof((a)))
#define f first
// #define s second
#define pb push_back
#define mk make_pair
#define all(g) g.begin(),g.end()
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }
int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }

// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_updat
// using namespace __gnu_pbds;
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

// I am questioning life and universe and 
// everything else after looking at this

const ll MAXN = 2e5 + 10;
ll A = 30;

string s;
char t[MAXN],d[MAXN];

ll check(ll p,ll n,ll q){
    FOR(i,1,q){
        if(t[i] == s[p]){
            if(d[i] == 'L') --p;
            else ++p;

            if(p<0 || p>=n) return p;
        }
    }

    return p;
}


void solve(){
    ll n,q;
    cin>>n>>q>>s;

    FOR(i,1,q){
        cin>>t[i]>>d[i];
    }

    ll ans = n;

    ll s = 0,e = n-1;

    while(s <= e){
        ll mid = (s+e)>>1;
        if(check(mid,n,q) < 0){
            s = mid+1;
        }else {
            e = mid-1;
        }
    }
    
    ans -= s;

    s = 0,e = n-1;

    while(s <= e){
        ll mid = (s+e)>>1;
        if(check(mid,n,q) >= n){
            e = mid-1;
        }else {
            s = mid+1;
        }
    }

    ans -= (n-1-e);
    cout<<ans<<endl;
}

signed main(){

 
    FastRead;    

    ll t;
    t = 1; 
    // cin>>t;
    while(t--) solve();
    
}