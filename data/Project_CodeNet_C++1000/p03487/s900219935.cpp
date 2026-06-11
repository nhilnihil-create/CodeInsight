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
	map<int, int> mp;
	for(int i = 0; i < n; i++){
		int x; cin>>x;
		mp[x]++;
	}
	int ans = 0;
	for(auto x : mp){
		if(x.second >= x.first)ans += x.second - x.first;
		else ans += x.second;
	}
	cout<<ans<<endl;

	return 0;
}