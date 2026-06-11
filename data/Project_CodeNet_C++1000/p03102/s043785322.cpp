#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(void){
	int N, M, C;
	cin >> N >> M >> C;
	int A[N][M];
	int B[M];
	rep(i,M) cin >> B[i];
	rep(i,N)rep(j,M) cin >> A[i][j];

	int ans = 0;
	rep(i,N){
		int score = C;
		rep(j,M) score += A[i][j]*B[j];
		if (score > 0) ans++;
	}
	cout << ans << endl;
	return 0;
}
