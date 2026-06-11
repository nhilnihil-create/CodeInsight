#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007, INF=mod*mod*3LL;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n, a, ans = 0;
    cin >> n;
    for(int i=0;i<n;i++){
    	cin >> a;
    	while(a%2 == 0){
    		a /= 2;
    		ans++;
    	}
    }
    cout << ans << endl;
    return 0;
}
