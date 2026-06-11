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
    ll n;
    cin >> n;
    ll a[n], ans = 0;;
    for(int i=0;i<n;i++){

    	cin >> a[i];
    	ans += a[i];
    }
    cout << ans - n << endl;
    return 0;

}
