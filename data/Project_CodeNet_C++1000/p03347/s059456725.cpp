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

signed main(){
    ll n;
    cin >> n;
    ll a[n] = {};
    rep(i,0,n){
        cin >> a[i];
    }
    if(a[0] != 0){
        cout << -1 << endl;
        return 0;
    }
    rep(i,0,n-1){
        if(a[i+1] - 1 > a[i]){
            cout << -1 << endl;
            return 0;
        }
    }

    ll x[n] = {},cnt = 0;
    rep(i,0,n-1){
        ll index = n-i-1;
        if(x[index] == a[index]) continue;
        if(a[index] -1 == a[index-1]) cnt++;
        else cnt += a[index];
    }
    cout << cnt << endl;
    return 0;
}
