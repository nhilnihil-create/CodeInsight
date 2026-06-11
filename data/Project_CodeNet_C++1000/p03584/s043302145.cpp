#include <iostream>
#include <vector>
using namespace std;
int main(){
	int N, K;
	cin >> N >> K;
	vector<int> A(N), B(N);
	for (int i = 0; i < N; i++){
		cin >> A[i] >> B[i];
	}
	long long ans = 0;
	int X = 0;
	for (int i = 29; i >= 0; i--){
		if (K >> i & 1){
			int Y = X + (1 << i) - 1;
			long long tmp = 0;
			for (int j = 0; j < N; j++){
				if ((Y & A[j]) == A[j]){
					tmp += B[j];
				}
			}
			ans = max(ans, tmp);
			X += 1 << i;
		}
	}
	long long tmp = 0;
	for (int i = 0; i < N; i++){
		if ((K & A[i]) == A[i]){
			tmp += B[i];
		}
	}
	ans = max(ans, tmp);
	cout << ans << endl;
}