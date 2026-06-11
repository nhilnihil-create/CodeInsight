#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007, INF=(1LL<<60);
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n, t ;
    cin >> n >> t;
    ll x, y;
    ll ans = INF;
    while(n--){
    	cin >> x >> y;
    	if(y <= t) ans = min(ans, x);
    }
    if(ans == INF) cout << "TLE" << endl;
    else cout << ans << endl;
    return 0;
}
