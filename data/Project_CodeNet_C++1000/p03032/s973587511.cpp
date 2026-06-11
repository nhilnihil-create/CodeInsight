#include "bits/stdc++.h"
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	vector<int>V(N);
	for (int n = 0;n<N;++n) {
		cin >> V[n];
	}
	int num = min(N,K);
	int ans = 0;
	for (int n = 0;n<=num;++n) {
		for (int a = 0;a<=n;++a) {
			vector<int>Bad;
			int b = n - a;
			int tmp = 0;
			for (int m = 0;m<a;++m) {
				tmp += V[m];
				if (V[m]<0) {
					Bad.push_back(V[m]);
				}
			}
			for (int m = 0;m<b;++m) {
				tmp += V[N - 1 - m]; 
				if (V[N - 1 - m] < 0) {
					Bad.push_back(V[N - 1 - m]);
				}
			}
			sort(Bad.begin(), Bad.end());
			for (int m = 0;m< min((int)Bad.size(),K-n);++m) {
				tmp -= Bad[m];
			}
			ans = max(ans, tmp);
		}
	}
	cout << ans <<  endl;
	return 0;
}