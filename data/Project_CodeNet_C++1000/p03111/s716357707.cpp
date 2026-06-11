#include "bits/stdc++.h"
using namespace std;

int main() {
	int N, A, B, C;
	cin >> N >> A >> B >> C;
	vector<int>L(N);
	for (int n = 0;n<N;++n) {
		cin >> L[n];
	}
	int ans = 1e9;
	for (int n = 0;n<(1<<2*N);++n) {
		int a = 0;
		int b = 0;
		int c = 0;
		int count = 0;
		int anstmp = 0;
		for (int m = 0;m<N;++m) {
			int tmp = (n>>(2*m))&3;
			if (0 == tmp) {
				a += L[m];
				count++;
			}
			else if (1 ==tmp) {
				b += L[m]; 
				count++;
			}
			else if ( 2== tmp){
				c += L[m]; 
				count++;
			}
		}
		count -= 3;
		if ((0 == a)||(0==b)||(0==c)) {
			continue;
		}
		anstmp += abs(a - A) + abs(b - B) + abs(c - C) + 10*count;
		ans = min(ans,anstmp);
	}
	cout << ans <<endl;
}
