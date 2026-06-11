#include "bits/stdc++.h"
using namespace std;

const int dx[] = { -1,0,1,0,0,1,-1,-1,1 };
const int dy[] = { 0,-1,0,1,0,1,-1,1,-1 };

int main() {
	long long N, M;
	cin >> N >> M;
	long long ans = 0;
	if ((1 == N) && (1 == M)) {
		ans = 1;
	}
	else if(1 == N){
		ans = M - 2;
	}
	else if (1 == M) {
		ans = N - 2;
	}
	else {
		ans = (N-2)*(M-2);
	}
	cout << ans << endl;
	return 0;
}