#include "bits/stdc++.h"
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	vector<int>X(N); 
	vector<int>Y(N);
	for (int i = 0; i < N; ++i) {
		cin >> X[i] >> Y[i];
	}
	vector<int>copyX = X;
	vector<int>copyY = Y;
	sort(copyX.begin(),copyX.end());
	sort(copyY.begin(),copyY.end());
	long long ans = (long long)4 * 1e18;
	for (int i = 0;i<N;++i) {
		for (int j = i + 1;j<N;++j) {
			for (int l = 0;l<N;++l) {
				for (int m = l + 1; m < N; ++m) {
					int count = 0;
					for (int n = 0;n<N;++n) {
						if ((X[n]>=copyX[i])&&(X[n]<=copyX[j])&&(Y[n]>=copyY[l])&&(Y[n]<=copyY[m])) {
							count++;
						}
					}
					//cout << copyX[i] <<"_"<<copyX[j] <<"_"<<copyY[l]<<"_"<<copyY[m]<<endl;
					//cout << count <<endl;
					if (count >= K) {
						ans = min(ans, (long long)(copyX[j] - copyX[i])*(long long)(copyY[m] - copyY[l]));
					}
				}
			}
		}
	}
	cout << ans <<endl;
	return 0;
}