#include "bits/stdc++.h"
using namespace std;

int main() {
	int N, M, C;
	cin >> N >> M >> C;
	vector<int>B(M); 
	for (int n = 0;n<M;++n) {
		cin >> B[n];
	}
	int ans = 0;	
	for (int n = 0;n<N;++n) {
		int memo = 0;
		for (int m = 0; m < M; ++m) {
			int num;
			cin >> num;
			memo += num * B[m];
		}
		if (memo+C>0) {
			ans++;
		}
	}
	cout << ans << endl;

}