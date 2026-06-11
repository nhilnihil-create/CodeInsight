#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int A, B, K;
	cin >> A >> B >> K;

	for (int i = A; i <= B; i++) {
		if (i < A + K) {
			cout << i << endl;
		}
		else if (i > B - K) {
			cout << i << endl;
		}
	}
}