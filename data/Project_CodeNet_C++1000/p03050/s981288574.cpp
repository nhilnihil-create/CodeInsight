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
    ll n;
    cin >> n;
    ll ans = 0;
    rep(i,1,sqrt(n)+1){
        if(n % i == 0){
            if(n/i-1 > 0 && n / (n/i-1) == n % (n/i-1) )ans += n/i-1;

            if(i*i != n && i > 1 && n / (i-1) == n % (i-1)) ans += i-1;
        }
    }

    cout << ans << endl;
    return 0;
}
