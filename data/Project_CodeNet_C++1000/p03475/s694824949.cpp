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
    vector<ll> c(n), s(n), f(n);
    for(int i=0;i<n-1;i++){
    	cin >> c[i] >> s[i] >> f[i];
    }
    for(int i=0;i<n;i++){
    	ll now = 0;
    	for(int j=i;j<n-1;j++){
    		now = max(now, s[j]);
    		ll maki = now + f[j] - 1;
    		maki /= f[j];
    		now = maki * f[j];
    		now += c[j];
    	}
    	cout << now << endl;
    }
    return 0;
}
