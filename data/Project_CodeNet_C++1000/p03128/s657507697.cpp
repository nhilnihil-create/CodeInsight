#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const long long INF = 1e18;
const int num[10] = {
	1000000000, 2, 5, 5, 4, 5, 6, 3, 7, 6
};

int main(){
	int N, M;
	cin >> N >> M;
	int A[M];
	for (int i = 0; i < M; i++){
		cin >> A[i];
	}
	sort(A, A + M, greater<int>());

	long long dp[N + 1] = {0};
	for (int i = 1; i <= N; i++){
		dp[i] = -INF;
		for (int j = 0; j < M; j++){
			if(i-num[A[j]] >= 0){
				dp[i] = max(dp[i], dp[i - num[A[j]]] + 1);
			}
		}
	}

	while (N > 0){
		for (int i = 0; i < M; i++){
			if (dp[N - num[A[i]]] == dp[N] - 1 && N - num[A[i]] >= 0){
				N -= num[A[i]];
				cout << A[i];
				break;
			}
		}
	}
	cout << endl;
	return 0;
}
