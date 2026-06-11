#include "bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

using namespace std;
const int INF = 1 << 30;
const long long MOD = 1000000000 + 7;
const double PI = acos(-1);

int main() {
	int A, B; cin >> A >> B;
	if (A > 12)cout << B;
	else if (A >= 6)cout << B / 2;
	else cout << 0;
}