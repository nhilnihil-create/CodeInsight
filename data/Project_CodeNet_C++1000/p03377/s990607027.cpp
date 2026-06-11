#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int A, B, X;
	cin >> A >> B >> X;

	if ((X >= A) && (X <= A + B)) cout << "YES" << endl;
	else cout << "NO" << endl;
}