#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(void){
	int N, M, X;
	cin >> N >> M >> X;
	int A[M];
	rep(i,M) cin >> A[i];

	int c[N+1];
	rep(i,N+1) c[i] = 0;
	rep(i,M) c[A[i]] = 1;
	int l = 0, r = 0;
	for (int i = 0; i < X; i++) {
		l += c[i];
	}
	for (int i = X+1; i < N; i++) {
		r += c[i];
	}

	cout << min(l,r) << endl;

	return 0;
}
