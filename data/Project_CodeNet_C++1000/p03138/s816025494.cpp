#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n; ll k;
	cin>>n>>k;
	vector<int> cnt(40, 0);
	for(int i = 0; i < n; i++){
		ll x; cin>>x;
		for(int j = 0; j < 40; j++){
			if((x>>j)&1)cnt[j]++;
		}
	}
	ll ans = 0;
	ll cur = 0;
	for(int i = 39; i >= 0; i--){
		if((k>>i)&1){
			ll tmp = cur + cnt[i]*(1LL<<i);
			for(int j = i - 1; j >= 0; j--){
				tmp += max(cnt[j], n - cnt[j])*(1LL<<j);
			}
			ans = max(ans, tmp);
			cur += (n - cnt[i])*(1LL<<i);
		}else{
			cur += cnt[i]*(1LL<<i);
		}
	}
	ans = max(ans, cur);
	cout<<ans<<endl;

	return 0;
}