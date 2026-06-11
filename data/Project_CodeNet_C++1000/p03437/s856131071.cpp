#include <bits/stdc++.h>

using namespace std;

#define FOE(i, s, t) for (int i = s; i <= t; i++)
#define FOR(i, s, t) for (int i = s; i < t; i++)
#define FOD(i, s, t) for (int i = s; i >= t; i--)

#define LL long long
#define mp make_pair
#define pb push_back

int gcd(int a, int b) {
	return (!b ? a : gcd(b, a % b));	
}

int main() {
	int x, y; cin >> x >> y;

	if (gcd(x, y) == y) {
		puts("-1");	
	} else {
		cout << x << endl;
	}
}