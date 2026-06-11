#include<bits/stdc++.h>
#define INF 2000000000
#define MOD 1000000007
#define EPS (1e-10)

using namespace std;

int main(int argc, char *argv[]) {

	int N,M,C; cin >> N >> M >> C;
	vector<int> B(N,0);

	for (int i = 0; i < M; i++) {
		cin >> B[i];
	}

	int ans = 0;
	for (int i = 0; i < N; i++) {
		int sum = 0;
		for (int j = 0; j < M; j++) {
			int a; cin >> a;
			sum += a * B[j];
		}
		if (sum + C > 0) {
			ans++;
		}
	}
	cout << ans << endl;
	


	return 0;
}
