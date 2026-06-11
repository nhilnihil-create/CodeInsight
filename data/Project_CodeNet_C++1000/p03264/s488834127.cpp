#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	int K;
	cin >> K;

	int o, e;
	o = 0;
	e = 0;

	for (int i = 1; i <= K; i++) {
		if (i % 2) o++;
		else e++;
	}

	cout << o * e << endl;
}