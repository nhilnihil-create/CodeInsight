#include<bits/stdc++.h>
#define INF 2000000000
#define MOD 1000000007
#define EPS (1e-10)

using namespace std;

int main(int argc, char *argv[]) {

	long N; cin >> N;
	if (N % 2 == 0) {
		cout << N << endl;
	}else {
		cout << 2 * N << endl;
	}
	return 0;
}
