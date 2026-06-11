#include <iostream>
#include <vector>
using namespace std;
int LOG = 40;
int main(){
	int N;
	long long K;
	cin >> N >> K;
	vector<long long> A(N);
	for (int i = 0; i < N; i++){
		cin >> A[i];
	}
	vector<int> cnt(LOG, 0);
	for (int i = 0; i < N; i++){
		for (int j = 0; j < LOG; j++){
			if (A[i] >> j & 1){
				cnt[j]++;
			}
		}
	}
	long long X = 0;
	for (int i = LOG - 1; i >= 0; i--){
		long long next = X + ((long long) 1 << i);
		if (cnt[i] * 2 < N && next <= K){
			X = next;
		}
	}
	long long ans = 0;
	for (int i = 0; i < N; i++){
		ans += X ^ A[i];
	}
	cout << ans << endl;
}