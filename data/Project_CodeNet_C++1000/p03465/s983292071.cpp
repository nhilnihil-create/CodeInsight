#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ss(x) (int) x.size()
#define cat(x) cerr << #x << " = " << x << endl

using ll = long long;

using namespace std;

const int N = 4000005;

int n, s, a;
bitset <N> B;

int main() {
	B[0] = 1;
	scanf ("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf ("%d", &a);
		s += a;
		B |= (B << a);
	}
	for (int i = (s + 1) / 2; true; ++i)
		if ((int) B[i] == 1) 
			return printf ("%d\n", i), 0;
	return 0;
}
