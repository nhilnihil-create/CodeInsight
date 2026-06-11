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
    ll a,b;
    cin >> a >> b; 
    a = max(a-1,0LL);
    switch(a%4){
        case 1:
            a = 1;
            break;
        case 2:
            a++;
            break;
        case 3:
            a = 0;
            break;
    }
    switch(b%4){
        case 1:
            b = 1;
            break;
        case 2:
            b++;
            break;
        case 3:
            b = 0;
            break;
    }

    cout << (a ^ b) << endl;

    return 0;
}
