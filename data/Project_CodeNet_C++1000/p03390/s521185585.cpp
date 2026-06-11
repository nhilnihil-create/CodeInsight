#include <iostream>
#include <vector>

using namespace std;

long long solve(long long A, long long B){
	if(A > B) swap(A, B);
	long long L = 0, R = B;
	while(R - L > 1){
		long long mid = (L+R)/2;
		if(mid * mid < A * B) L = mid;
		else R = mid;
	}
	if(L < A) return 2 * L;
	if(L * (L+1) < A * B) return 2 * L - 1;
	return 2 * L - 2;
}

int main(){
	int Q;
	while(cin >> Q){
		while(Q--){
			long long A, B; cin >> A >> B;
			cout << solve(A, B) << endl;
		}
	}
}
