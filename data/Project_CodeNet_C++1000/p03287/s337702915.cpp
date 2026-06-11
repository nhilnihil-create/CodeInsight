#include "bits/stdc++.h"
using namespace std;

int main() {
	long long N,M;
	cin >> N >> M;
	vector<long long>A(N);
	long long num = 0;
	map<long long, long long>mp;
	long long ans = 0;
	mp[0] = 1;
	for (int i = 0;i<N;++i) {
		cin >> A[i];
		num += A[i];
		num %= M;
		mp[num]++;
	}
	for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
		ans += (itr->second)*(itr->second - 1) / 2;
	}
	cout << ans << endl;
	return 0;
}