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

	int n; cin>>n;
	vector<int> v;
	for(int p = 2; p <= n; p++){
		bool ok = true;
		for(int q = 2; q < p; q++){
			if(p%q == 0){
				ok = false;
				break;
			}
		}
		if(!ok)continue;
		int tmp = n;
		int cnt = 0;
		while(tmp){
			cnt += tmp/p;
			tmp /= p;
		}
		v.push_back(cnt);
	}
	vector<ll> cnt(100, 0);
	for(auto x : v){
		for(int i = 1; i <= x; i++){
			cnt[i]++;
		}
	}
	ll ans = cnt[74];
	ans += cnt[24]*(cnt[2] - 1);
	ans += cnt[14]*(cnt[4] - 1);
	ans += cnt[4]*(cnt[4] - 1)*(cnt[2] - 2)/2;
	cout<<ans<<'\n';

	return 0;
}