#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int D, N;
	cin >> D >> N;

	if (N == 100) N++;

	cout << N;
	for (int i = 0; i < D; i++) {
		cout << "00";
	}
	cout << endl;
}