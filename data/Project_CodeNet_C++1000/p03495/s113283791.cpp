#include "bits/stdc++.h"

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	map<int, int>mp;
	for (int i = 0;i<N;++i) {
		int a;
		cin >> a;
		mp[a]++;
	}
	vector<int>vec;
	for (auto a:mp) {
		vec.push_back(a.second);
	}
	sort(vec.rbegin(),vec.rend());
	int ans = 0;	
	for (int i = K; i < vec.size(); ++i) {
		ans += vec[i];
	}
	cout << ans <<  endl;
	return 0;
}
