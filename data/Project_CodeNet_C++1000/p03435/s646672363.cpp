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
    ll a[3],b[3] = {};
    ll c[3][3] = {};
    ll test[3][3] = {};
    rep(i,0,3) rep(j,0,3) cin >> c[i][j];
    b[0] = 0; 
    a[0] = c[0][0]; a[1] = c[0][1] - b[0]; a[2] = c[0][2] - b[0];
    b[1] = c[1][0] - a[0]; b[2] = c[2][0] - a[0];

    rep(i,0,3){
        rep(j,0,3){
            if(c[i][j] != a[j] + b[i]){
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;


    return 0;
}
