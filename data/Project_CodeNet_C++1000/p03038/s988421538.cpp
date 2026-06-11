#include "bits/stdc++.h"
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<int>A(N);
	map<int, int>mp;
	for (int n = 0;n<N;++n) {
		cin >> A[n];
		mp[-A[n]]++;
	}
	for (int m = 0;m<M; ++m) {
		int B, C;
		cin >> B >> C;
		mp[-C] += B;
	}
	long long ans = 0;
	for (auto itr = mp.begin();itr!=mp.end();++itr) {
		if (itr->second >=N) {
			ans += (long long)N * (-1*itr->first);
			break;
		}
		else {
			ans += (long long)itr->second * (-1 * itr->first);
			N -= itr->second;
		}
	}
	cout << ans <<  endl;
	return 0;
}