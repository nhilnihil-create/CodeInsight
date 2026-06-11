#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL -1
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int N, K;
	cin >> N >> K;
	
	int n = 1;
	for (int i = 0; i < N; i++) {
		if (n < K) n *= 2;
		else n += K;
	}

	cout << n << endl;
}
