#include <bits/stdc++.h>
using namespace std;

#define int long long
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

vector<int> a;
map<int, int> mp;

vector<int> vec;

int get(){
	int ans = INT_MAX;
	for(int i = 0;i < vec.size();i++){
		for(int j = i+1;j < vec.size();j++){
			int mi = min(vec[i], vec[j]);
			int ma = max(vec[i], vec[j]);
			chmin(ans, min(ma-mi, 24-ma + mi));
		}
	}
	return ans;
}

int dfs(int i){
	if(i > 12){
		return get();
	}

	if(i == 0){
		if(mp[i] > 1) return 0;
		vec.push_back(0);
		return dfs(i+1);
	}

	if(mp[i] > 2){
		return 0; 
	}

	if(mp[i] == 0){
		return dfs(i+1);
	}

	if(mp[i] == 2){
		vec.push_back(i);
		vec.push_back(24-i);
		int ans = dfs(i+1);
		vec.pop_back();
		vec.pop_back();
		return ans;
	}

	vec.push_back(i);
	int ans = dfs(i+1);
	vec.back() = 24-i;
	chmax(ans, dfs(i+1)); 
	vec.pop_back();
	return ans; 
}

signed main(){
	int n;
	cin >> n;

	mp[0]++;
	for(int i = 0;i < n;i++){
		int d;
		cin >> d;
		mp[d]++;
	}

	cout << dfs(0) << endl;

	return 0;
}
