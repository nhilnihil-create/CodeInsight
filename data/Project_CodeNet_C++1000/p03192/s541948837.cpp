#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	int N;
	cin >> N;

	int cnt = 0;
	while (N > 0) {
		int n = N % 10;
		if (n == 2) cnt++;
		N /= 10;
	}

	cout << cnt << endl;
}