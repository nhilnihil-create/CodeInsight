#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int N, M;
	cin >> N >> M;
	int L[M], R[M];
	rep(i,M) cin >> L[i] >> R[i];

	int pass[N+1];
	rep(i,N+1) pass[i] = 0;
	
	rep(i,M) {
		pass[L[i]-1] += 1;
		pass[R[i]] -= 1;
	}

			
	for (int i = 1; i <= N; i++) {
		pass[i] += pass[i-1];
	}

	int ans = 0;
	rep(i,N) if (pass[i] == M) ans++;

	cout << ans << endl;

	return 0;
}
