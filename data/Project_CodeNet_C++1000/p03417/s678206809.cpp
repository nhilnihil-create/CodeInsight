#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define ll long long
#define rep(i,n) for (ll i = 0; i < (ll)(n); ++i)
#define be(v) (v).begin(), (v).end()
#define dcout cout << fixed << setprecision(20) 
ll INF = 1LL << 60;
ll mod = 1e9 + 7;

int main() {
	ll n,m; cin >> n >>m;
	if(n>m) swap(n,m);
	if(n==1) {
		if(m==1){
		cout << 1 << endl;
		return 0;
	}
		cout << m-2 << endl;
		return 0;
	}
	ll ans = (m-2)*(n-2);
	cout << ans << endl;
}