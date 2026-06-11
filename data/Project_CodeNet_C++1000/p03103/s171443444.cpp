#include "bits/stdc++.h"
using namespace std;

int main() {
	int N,M;
	cin >> N>>M;
	map<int, int>mp;
	for (int n = 0;n<N;++n) {
		int A, B;
		cin >> A >> B;
		mp[A] += B;
	}
	long long ans = 0;
	for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
		if (M >= itr->second) {
			ans += (long long)itr->first * itr->second;
			M -= itr->second;
		}
		else {
			ans += (long long)itr->first * M;
			M = 0;
		}
		if (0 == M) {
			break;
		}

	}
	cout << ans <<  endl;
}
