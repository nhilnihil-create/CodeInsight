#include <bits/stdc++.h>
using namespace std;

long long N, A[200100];
long long psum[200100], pxor[200100];
long long ans = 0;

long long sum(int L, int R) {
	return psum[R]-psum[L-1];
}

long long sor(int L, int R) {
	return pxor[R]^pxor[L-1];
}

int main () {
	cin >> N;
	for(int i=1; i<=N; i++) {
		cin >> A[i];
		psum[i] = psum[i-1] + A[i];
		pxor[i] = pxor[i-1] ^ A[i];
	}
	for(int i=1; i<=N; i++) {
		int ki = i;
		int ka = N;
		int res= i;
		while(ki <= ka) {
			int mid = (ki+ka)/2;
			if (sum(i,mid)==sor(i,mid)) {
				res = mid;
				ki = mid+1;
			} else {
				ka = mid-1;
			}
		}
		//cout << i << " " << res << endl;
		ans += res-i+1;
	}
	cout << ans << endl;
}
