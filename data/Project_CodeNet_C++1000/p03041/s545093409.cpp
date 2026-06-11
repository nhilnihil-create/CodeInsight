#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int GCD(int a, int b) {
	if (!b) return a;
	else {
		return GCD(b, a % b);
	}
}

int main() {
	int N, K;
	cin >> N >> K;

	K--;
	for (int i = 0; i < N; i++) {
		char c;
		cin >> c;
		if (i == K) {
			int n = (int)c + 32;
			cout << (char)n;
		}
		else {
			cout << c;
		}
	}
	cout << endl;
}