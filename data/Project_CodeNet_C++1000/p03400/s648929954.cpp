#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int N, D, X;
	cin >> N >> D >> X;
	int A[N];
	rep(i,N) cin >> A[i];

	rep(i,N)rep(j,101) {
			int d = j*A[i]+1;
			if (d>D) break;
			X++;
	}
	cout << X << endl;

	return 0;
}
