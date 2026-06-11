#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,a,n) for(ll i = a;i < n;i++)
#define rrep(i,a,n) for(ll i = n; i >= a;i--)
#define index_check(i,n) if(i > n-1 || i < 0) continue; 
#define LINF 1e18
#define INF 1e9
#define MOD (ll)(1e9+7)
using namespace std;

#define fs first
#define sc second

using P = pair<ll,ll>;
using Pll = pair<P,ll>;
using PQ = priority_queue<P,vector<P>,greater<P>>;

signed main(){
    ll a[3];
    rep(i,0,3){
        cin >> a[i];
    }

    sort(a,a+3);
    ll cnt = 0;
    if((a[2] - a[1]) % 2 && (a[2] - a[0]) % 2){
        cnt += (a[2] - a[1])/2;
        cnt += (a[2] - a[0])/2;
        cnt++;
    }
    else if((a[2] - a[1]) % 2 == 0 && (a[2] - a[0]) % 2 == 0){
        cnt += (a[2] - a[1]) / 2;
        cnt += (a[2] - a[0]) / 2;
    }
    else{
        cnt += (a[2] - a[1]) / 2;
        cnt += (a[2] - a[0]) / 2;
        cnt += 2;
    }

    cout << cnt << endl;
    return 0;
}
