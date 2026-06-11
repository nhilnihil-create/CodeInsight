#include <vector>
#include <iostream>
using namespace std;
int main() {
	int N, M;
	cin >> N >> M;
	vector<int> bit(M), p(M);
	for(int i = 0; i < M; ++i) {
		int c, x;
		cin >> c;
		for(int j = 0; j < c; ++j) {
			cin >> x;
			bit[i] |= 1 << (--x);
		}
	}
	for(int i = 0; i < M; ++i) {
		cin >> p[i];
	}
	int ways = 0;
	for(int i = 0; i < (1 << N); ++i) {
		bool ok = true;
		for(int j = 0; j < M; ++j) {
			if((__builtin_popcount(i & bit[j]) & 1) != p[j]) {
				ok = false;
				break;
			}
		}
		if(ok) ++ways;
	}
	cout << ways << endl;
	return 0;
}