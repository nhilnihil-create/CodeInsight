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
	vector<int> v[20];
	ll ans = 0;
	for(int i = 1; i <= n; i++){
		int x; cin>>x;
		for(int j = 0; j < 20; j++){
			if((x>>j)&1)v[j].push_back(i);
		}
		int l = 0;
		for(int j = 0; j < 20; j++){
			if(v[j].size() <= 1)continue;
			l = max(l, v[j][v[j].size() - 2]);
		}
		ans += i - l;
	}
	cout<<ans<<'\n';

	return 0;
}