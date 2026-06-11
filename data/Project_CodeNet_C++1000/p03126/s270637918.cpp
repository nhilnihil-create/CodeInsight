#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int N, M;
	cin >> N >> M;
	int B[M+1];
	rep(i,M+1) B[i] = 0;
	rep(i,N){
		int K;
		cin >> K;
		rep(j,K){
			int k;
			cin >> k;
			B[k]++;
		}
	}

	int ans = 0;
	for (int i = 1; i <= M; i++) {
		if (B[i] == N) ans++;
	}
	
	cout << ans << endl;
	
	return 0;
}
