#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int N, A, B;
	cin >> N >> A >> B;

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		int s = 0;
		int n = i;
		while (n) {
			s += n % 10;
			n /= 10;
		}

		if ((s >= A) && (s <= B)) ans += i;
	}

	cout << ans << endl;
}