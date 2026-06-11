#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int N, M;
	cin >> N >> M;
	vector<vector<long long>> A(N, vector<long long>(3));
	for (int i = 0; i < N; i++){
		for (int j = 0; j < 3; j++){
			cin >> A[i][j];
		}
	}
	long long ans = 0;
	for (int i = 0; i < (1 << 3); i++){
		vector<long long> S(N, 0);		
		for (int j = 0; j < N; j++){
			for (int k = 0; k < 3; k++){
				if (i >> k & 1){
					S[j] += A[j][k];
				} else {
					S[j] -= A[j][k];
				}
			}
		}
		sort(S.begin(), S.end());
		reverse(S.begin(), S.end());
		long long sum = 0;
		for (int j = 0; j < M; j++){
			sum += S[j];
		}
		ans = max(ans, sum);
	}
	cout << ans << endl;
}