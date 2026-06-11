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
    string s;
    ll k;
    cin >> s >> k;
    ll roopcnt = 0;
    while(roopcnt < (ll)s.size()){
        if(s[roopcnt] != '1'){
            cout << s[roopcnt] << endl; 
            break;
        }
        else if(roopcnt == k-1){
            cout << 1 << endl;
            break;
        }

        roopcnt++;
    }

    return 0;
}
