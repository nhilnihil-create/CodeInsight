#include "bits/stdc++.h"

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int>C(N); 
	vector<int>S(N); 
	vector<int>F(N);
	for (int i = 0;i<N-1;++i) {
		cin >>C[i]>>S[i]>>F[i];
	}
	vector<int>Ans(N); 
	for (int i = N-2; i >= 0; --i) {
		int time = C[i] + S[i];
		if (i== N-2) {
			Ans[i] = time;
			continue;
		}
		for (int j = i + 1;j<N-1;++j) {
			if (S[j]>=time) {
				Ans[i] = Ans[j];
				break;
			}
			else {
				if (0 == time % F[j]) {
					time = time + C[j];
				}
				else {
					time = time + C[j] - time % F[j]+F[j];
				}
				if (N-2 == j) {
					Ans[i] = time;
				}
			}
		}
	}	
	for (int i = 0; i < N; ++i) {
		cout << Ans[i]<<endl;
	}
	return 0;
}
