#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,a,n) for(ll i = a;i < n;i++)
#define rrep(i,a,n) for(ll i = n; i >= a;i--)
#define index_check(i,n) if(i > n-1 || i < 0) continue; 
#define LINF 1e18
#define INF 1e9
using namespace std;

#define fs first
#define sc second

using P = pair<ll,ll>;
using Pll = pair<P,ll>;
using PQ = priority_queue<P,vector<P>,greater<P>>;


const ll MOD = 1e9+7;


signed main(){
    ll n,ans = 0;
    cin >> n;
    ll a[n],b[n];
    
    P d[n];
    rep(i,0,n){
        cin >> a[i] >> b[i];
        d[i] = P(a[i]+b[i],i);
        ans -= b[i];
    }

    sort(d,d+n,greater<P>());

    rep(i,0,n){
        ans += d[i].fs ;
        i++;
    }

    cout << ans << endl;
    return 0;
}
