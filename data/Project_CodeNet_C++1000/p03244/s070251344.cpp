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

	int n;
	cin>>n;
	map<int, int> mp[2];
	for(int i = 0; i < n; i++){
		int x; cin>>x;
		mp[i&1][x]++;
	}
	vector<pair<int, int> > v[2];
	for(auto x : mp[0]){
		v[0].push_back({x.second, x.first});
	}
	for(auto x : mp[1]){
		v[1].push_back({x.second, x.first});
	}
	sort(v[0].rbegin(), v[0].rend());
	sort(v[1].rbegin(), v[1].rend());
	int ans;
	if(v[0][0].second != v[1][0].second){
		ans = n - v[0][0].first - v[1][0].first;
	}else if(v[0].size() == 1 && v[1].size()){
		ans = n/2;
	}else if(v[0].size() == 1){
		ans = n/2 - v[1][1].first;
	}else if(v[1].size() == 1){
		ans = n/2 - v[0][1].first;
	}else{
		ans = n - max(v[0][0].first + v[1][1].first, v[0][1].first + v[1][0].first);
	}
	cout<<ans<<endl;

	return 0;
}