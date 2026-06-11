#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int A, B, C, X;
	cin >> A >> B >> C >> X;

	int cnt = 0;
	for (int i = 0; i <= A; i++) {
		for (int j = 0; j <= B; j++) {
			int n = 500 * i + 100 * j;
			if (n > X) continue;
			int m = X - n;
			if ((m % 50 == 0)&&(m/50<=C)) cnt++;
		}
	}

	cout << cnt << endl;
}