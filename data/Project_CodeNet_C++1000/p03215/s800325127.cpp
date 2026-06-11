#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, k; cin >> n >> k;
	vector<long long> s(n+1, 0);
	for(int i = 1; i <= n; i++){
		cin >> s[i];
		s[i] += s[i-1];
	}
	vector<long long> v;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < i; j++){
			v.push_back(s[i] - s[j]);
		}
	}
	long long ans = 0;
	for(int i = 39; i >= 0; i--){
		long long nex = ans + (1LL << i);
		int cnt = 0;
		for(long long x : v){
			long long hoge = (x & nex);
			if(hoge == nex) cnt++;
		}
		if(cnt >= k) ans = nex;
	}
	cout << ans << endl;
	return 0;
}