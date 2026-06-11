#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long INF = 1000000000000000;
long long d(long long P, long long Q, long long R, long long S){
	return max({P, Q, R, S}) - min({P, Q, R, S});
}
int main(){
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++){
		cin >> A[i];
	}
	vector<long long> S(N + 1, 0);
	for (int i = 0; i < N; i++){
		S[i + 1] = S[i] + A[i];
	}
	long long ans = INF;
	for (int i = 2; i <= N - 2; i++){
		long long PQ = S[i];
		long long RS = S[N] - S[i];
		int p1 = lower_bound(S.begin(), S.end(), PQ / 2) - S.begin();
		long long P1 = S[p1];
		long long Q1 = PQ - P1;
		long long P2;
		long long Q2;
		if (p1 > 0){
			P2 = S[p1 - 1];
			Q2 = PQ - P2;
		}
		int p2 = lower_bound(S.begin(), S.end(), PQ + RS / 2) - S.begin();
		long long R1 = S[p2] - PQ;
		long long S1 = RS - R1;
		long long R2;
		long long S2;
		if (p2 > i){
			R2 = S[p2 - 1] - PQ;
			S2 = RS - R2;
		}
		ans = min(ans, d(P1, Q1, R1, S1));
		if (p1 > 0){
			ans = min(ans, d(P2, Q2, R1, S1));
		}
		if (p2 > i){
			ans = min(ans, d(P1, Q1, R2, S2));
			if (p1 > 0){
				ans = min(ans, d(P2, Q2, R2, S2));
			}
		}
	}
	cout << ans << endl;
}