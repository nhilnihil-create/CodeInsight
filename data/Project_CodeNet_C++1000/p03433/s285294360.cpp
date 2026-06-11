#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int N, A;
	cin >> N >> A;

	N %= 500;

	if (N <= A) cout << "Yes" << endl;
	else cout << "No" << endl;
}