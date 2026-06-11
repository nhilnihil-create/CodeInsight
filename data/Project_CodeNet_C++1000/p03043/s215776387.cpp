#include<bits/stdc++.h>
using namespace std;

#define ll long long
//~ #define endl '\n'

void solve(){
	cout<<fixed<<setprecision(20);
	int n, k; cin>>n>>k;
	double n_ = n, ans = 0;
	for(int i = 1; i<=n; i++){
		double a = 1.0;
		int b = i;
		while(b < k){
			b = b * 2;
			a = a * 0.5;
		}
		//~ cout<<i<<" "<<(1.0 / n_)<<" "<<a<<endl;
		ans += ((1.0 / n_) * a);
	}
	cout<<ans<<endl;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1; //cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
