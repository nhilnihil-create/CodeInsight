#include<bits/stdc++.h>

using namespace std;

bool comp(pair<int,int> a, pair<int,int> b){
	return a.first < b.first;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,t;
	cin >> n >> t;
	vector<pair<int,int>> v;
	for(int i=0; i<n; i++){
		int cost, time;
		cin >> cost >> time;
		v.push_back(make_pair(cost, time));
	}
	sort(v.begin(), v.end(), comp);
	for(auto x:v){
		if(x.second <= t){
			cout << x.first;
			return 0;
		}
	}
	cout << "TLE";
	return 0;
}