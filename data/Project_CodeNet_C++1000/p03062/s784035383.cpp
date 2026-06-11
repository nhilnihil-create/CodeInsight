#include<bits/stdc++.h>
#define INF 2000000000
#define MOD 1000000007
#define EPS (1e-10)

using namespace std;

int main(int argc, char *argv[]) {

	int N; cin >> N;

	int minus = 0;
	int idx = 0;
	int absMin = INF;
	vector<long> A(N,0);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		if (A[i] < 0) {
			minus++;	
		}
		if (absMin > abs(A[i])) {
			absMin = abs(A[i]);	
			idx = i;
		}
	}

	if (minus % 2 == 0) {
		for (int i = 0; i < N-1; i++) {
			if (A[i] < 0) {
				A[i] *= -1;	
				A[i+1] *= -1;	
			}
		}
	}else { //abs min search
		for (int i = 0; i < N-1; i++) {
			if (idx == i) {
				if (A[i] > 0) {
					A[i] *= -1;
					A[i+1] *= -1;
				}
			}else if (A[i] < 0) {
				A[i] *= -1;	
				A[i+1] *= -1;	
			}
		}
	}


	long sum = 0;
	for (int i = 0; i < N; i++) {
		sum += A[i];
	}
	cout << sum << endl;
	return 0;
}
