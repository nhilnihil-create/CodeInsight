#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	int N = 5;
	vector <int> t(N);
	for (int ii = 0; ii < N; ++ii){
		cin >> t[ii];
	}

	vector <int> v;
	for (int ii = 0; ii < N; ++ii){
		v.push_back(ii);
	}

	int ans = 1001001001;
	do {
		int time = 0;
		for (int ii = 0; ii < N; ++ii){
			if (time % 10 != 0){
				int val = time / 10;
				time = 10 * (val + 1);
			}
			time += t[v[ii]];
		}
		ans = min(ans, time);
	} while(next_permutation(v.begin(), v.end()));

	cout << ans << "\n";

	return 0;
}
