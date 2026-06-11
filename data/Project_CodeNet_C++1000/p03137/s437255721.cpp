#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int N, M;
	cin >> N >> M;
	int X[M];
	rep(i,M) cin >> X[i];

	if (N >= M) {
		cout << 0 << endl;
		return 0;
	}

	sort(X,X+M);
	int Y[M-1];
	rep(i,M-1) Y[i] = X[i+1] - X[i];
	sort(Y,Y+M-1);
	int ans = 0;
	rep(i,M-N) ans += Y[i];

	cout << ans << endl;

return 0;
}
