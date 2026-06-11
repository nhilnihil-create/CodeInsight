#include "bits/stdc++.h"

using namespace std;
int main() {
	int N, K;
	cin >> N >> K;
	double ans = 0;
	for (int n = 1;n<=N;++n) {
		int tmpn = n;
		int count = 0;
		while (tmpn <K) {
			tmpn *= 2;
			++count;
		}
		int memo = 1;
		for (int n=0;n<count;++n) {
			memo *= 2;
		}
		ans += 1.0 / N / memo;
	}
	printf("%.10f\n", ans);
}
