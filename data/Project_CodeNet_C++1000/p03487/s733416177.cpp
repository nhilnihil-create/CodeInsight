#include<bits/stdc++.h>
using namespace std;
// abc082 C

int main() {
	int n;
	cin >> n;
	unordered_map<int, int> mp;
	for(int i = 0; i < n; i++) {
		int _;
		cin >> _;
		mp[_]++;
	}
	int ans = 0;
	for(auto m: mp) {
		int num = m.first;
		int freq = m.second;
		if(num > freq) ans += freq;
		else ans += freq-num;
	}
	printf("%d", ans);
}
