#include <bits/stdc++.h>

#define boost ios_base::sync_with_stdio(false), cin.tie(NULL);

using namespace std;
const int N = 1e6 + 41;
const int mod = 1e9 + 7;
const long long INF = 1e16;
const int inf = 1e9;

int main () {
	boost;
	int m, k;
	cin >> m >> k;
	if (!k) {
		for (int i = 0 ; i < (1 << m) ; ++ i) cout << i << " " << i << " ";
	} else {
		int x = 0;
		int a = -1, b = -1;
		for (int i = 0 ; i < (1 << m) ; ++ i) x ^= i;
		for (int i = 0 ; i < (1 << m) ; ++ i) if ((x ^ k ^ i) < (1 << m) && (x ^ k ^ i) >= 0 && (x ^ k ^ i) != i) a = i, b = (x ^ k ^ i);
		if (a == -1) return cout << -1, 0;
		for (int i = 0 ; i < (1 << m) ; ++ i) if (i != a && i != b) cout << i << " ";
		cout << a << " " << b << " ";
		for (int i = (1 << m) - 1 ; i >= 0 ; -- i) if (i != a && i != b) cout << i << " ";
		cout << b << " " << a;
	}
}
