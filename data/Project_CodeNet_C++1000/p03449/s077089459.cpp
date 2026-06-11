#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int N;
	cin >> N;

	int t[N+1], b[N+1];
	rep(i,N) {
		t[i] = 0;
		b[i] = 0;
	}
	for (int i = 1; i <= N; i++) {
		int a;
		cin >> a;
		t[i] = t[i-1] + a;
	}
	int totb = 0;
	for (int i = 1; i <= N; i++) {
		int a;
		cin >> a;
		b[i] = b[i-1] + a;
		totb += a;
	}
	for (int i = N; i > 0; i--) {
		b[i] = totb - b[i-1];
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		ans = max(ans,t[i]+b[i]);
	}

	cout << ans << endl;
		
	return 0;
}
