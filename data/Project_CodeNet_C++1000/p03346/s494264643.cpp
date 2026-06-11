#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

int main() {
	int n; cin >> n;
	vector <int> a(n);
	rep(i, n) cin >> a[i], -- a[i];
	vector <int> ps(n);
	rep(i, n) ps[a[i]] = i;
	vector <int> f(n);
	rep(i, n) {
		if (i && ps[i - 1] < ps[i]) f[i] = f[i - 1];
		++ f[i];
	}
	int ans = 0;
	rep(i, n) ans = max(ans, f[i]);
	printf("%d\n", n - ans);
	return 0;
}
