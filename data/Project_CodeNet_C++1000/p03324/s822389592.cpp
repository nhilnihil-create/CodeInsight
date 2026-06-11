
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
typedef int64_t ll;

int D, N;

int main() {
	cin >> D >> N;
	if (D == 0) {
		if (N < 100) {
			cout << N << endl;
		}
		else {
			cout << 101 << endl;
		}
		
	}
	else if (D == 1) {
		if (N < 100) {
			cout << N * 100 << endl;
		}
		else {
			cout << 101 * 100 << endl;
		}
	}
			
	else if (D == 2) {
		if (N < 100) {
			cout << N * 100 * 100 << endl;
		}
		else {
			cout << 101 * 100 * 100 << endl;
		}
		
	}
}
