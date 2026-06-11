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

	int n, k;
	cin>>n>>k;
	map<int, int> mp;
	for(int i = 0; i < n; i++){
		int x; cin>>x;
		mp[x]++;
	}
	vector<int> v;
	for(auto x : mp){
		v.push_back(x.second);
	}
	sort(v.rbegin(), v.rend());
	int ans = 0;
	while(v.size() > k){
		ans += v.back(); v.pop_back();
	}
	cout<<ans<<endl;

	return 0;
}