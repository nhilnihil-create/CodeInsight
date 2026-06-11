#include<bits/stdc++.h>
#define INF 2000000000
#define MOD 1000000007
#define EPS (1e-10)

using namespace std;

int main(int argc, char *argv[]) {

	int N; cin >> N;

	int M = N / 2;
	if (N % 2 == 0) {
		cout << M * M << endl;	
	}else {
		cout << M * (M+1) << endl;	
	}
	return 0;
}
