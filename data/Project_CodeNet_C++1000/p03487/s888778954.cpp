#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, d; cin >> N;
	unordered_map <int,int> mp;
	for (int i = 0; i < N; ++i){
		cin >> d;
		++mp[d];
	}
	int cnt = 0;
	for (auto it = mp.begin(); it != mp.end(); ++it){
		if (it-> first > it->second){
			cnt += it->second;
		}else{
			cnt += it->second - it->first;
		}
	}
	cout << cnt << "\n";
	return 0;
}
