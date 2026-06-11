#include "bits/stdc++.h"
using namespace std;

int main() {
	int D;
	long long G;
	cin >> D >> G;
	vector<long long>P(D);
	vector<long long>C(D);
	for (int i = 0;i<D; ++i) {
		cin >> P[i] >> C[i];
	}
	long long Ans = 1e18;
	for (int i = 0;i<(1<<D);++i) {
		long long ans = 0;
		long long g = 0;
		for (int j = 0; j < D; ++j) {
			if (0 != ((i >> j) & 1)) {
				ans += P[j];
				g += P[j] * 100 * (j + 1) +C[j];
			}
		}		
		for (int j = D - 1; j >= 0; --j) {
			if (g < G) {
				if (0 == ((i >> j) & 1)) {
					long long count = (G - g) / (100 * (j + 1)); 
					if (0 != (G - g) % (100 * (j + 1))) {
						count++;
					}
					count = min(P[j]-1,count);
					ans += count;
					g += count * 100 * (j + 1);
				}
			}
		}	
		if (g >= G) {
			Ans = min(ans ,Ans);
		}
	}
	cout << Ans << endl;
}
