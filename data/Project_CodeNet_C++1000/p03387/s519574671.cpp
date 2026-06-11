#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int A, B, C;
	cin >> A >> B >> C;

	int M = max(max(A, B), C);
	int sum = A + B + C;
	if ((M * 3 - sum) % 2) M++;

	cout << (M * 3 - sum) / 2 << endl;
}