#include<bits/stdc++.h>
#define INF 2000000000
#define MOD 1000000007
#define EPS (1e-10)

using namespace std;

int main(int argc, char *argv[]) {

	int N,K; cin >> N >> K;

	if (N % K == 0) {
		cout << 0 << endl;
	}else {
		cout << 1 << endl;
	}
	return 0;
}
