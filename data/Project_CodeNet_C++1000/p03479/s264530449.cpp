#include<bits/stdc++.h>
 
#define rep(i,n) for(ll i = 0;i < n;++i)
#define all(v) v.begin(),v.end()
using namespace std;
using ll = long long;
typedef pair<int,int> P;
 
const int INF = 1001001001;
const long double PI = (acos(-1));
const int mod = 1e9+7;
const int vx[4] = {0,1,0,-1};
const int vy[4] = {1,0,-1,0};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll x,y;
    cin >> x >> y;
    ll ans = 0;
    while(x <= y){
        x*=2;
        ans++;
    }
    cout << ans << endl;
    

    return 0;
}
