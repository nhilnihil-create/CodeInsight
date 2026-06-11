#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int N, K;
	cin >> N >> K;

	int n = (N - 1) / (K - 1);
	if ((N - 1) % (K - 1)) n++;

	cout << n << endl;
}