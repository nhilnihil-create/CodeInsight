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

	int n, m;
	cin>>n>>m;
	map<int, int> mp;
	ll cur = 0, ans = 0;
	mp[0] = 1;
	for(int i = 0; i < n; i++){
		int x; cin>>x;
		cur = (cur + x)%m;
		ans += mp[cur];
		mp[cur]++;
	}
	cout<<ans<<endl;

	return 0;
}