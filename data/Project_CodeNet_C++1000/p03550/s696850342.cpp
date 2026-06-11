#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
#define vcout(v) rep(i,v.size()) cout << v[i] << " "; cout << endl
#define mcout(m) rep(j,m.size()){vcout(m[j]);}
const ll MOD = 1e9 + 7;

void mainsolve(){

	ll n,z,w;
	cin >> n >> z >> w;

	vector<ll> a(n+1);
	a[0] = w;
	rep(i,n) cin >> a[i+1];

	if(n==1){
		cout << abs(a[n] - w) << endl;
		return;
	}

	vector<ll> dp1(n,-1),dp2(n, MOD);
	dp1[n-1] = dp2[n-1] = abs(a[n] - a[n-1]);


	for(ll i = n-2; i >= 0; i--){
		for(ll j = i+1; j < n; j++){
			dp1[i] = max(dp1[i],dp2[j]);
			dp2[i] = min(dp2[i],dp1[j]);
		}
		dp1[i] = max(dp1[i], abs(a[n]-a[i]));
		dp2[i] = min(dp2[i], abs(a[n]-a[i]));
	}

	cout << dp1[0] << endl;

	return;
}

int main(){
	
	//ll TC;cin>>TC;rep(I,TC){cout<<"case:"<<I+1<<"---"<<endl; // comment out!
		mainsolve();
	//} // comment out!
	return 0;
}