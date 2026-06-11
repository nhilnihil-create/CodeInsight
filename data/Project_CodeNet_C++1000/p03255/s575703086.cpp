#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

namespace io {
	const int maxb = 1 << 15;
	char b[maxb], *s = b, *t = b;
	
	bool getchar(char &ch) {
		return ch = s == t && (t = (s = b) + fread(b, 1, maxb, stdin)) == b ? 0 : *s++;
	}
	
	int getint() {
		char ch;
		while (getchar(ch) && (ch < '0' || ch > '9'));
		int s = ch - '0';
		while (getchar(ch) && ch >= '0' && ch <= '9') {
			s = s * 10 + ch - '0';
		}
		return s;
	}
}

using io::getint;

const int maxn = 2e5 + 10;

int main() {
	int n = getint(), X = getint();
	static ll s[maxn];
	for (int i = n; i; --i) s[i] = getint();
	for (int i = 1; i <= n; ++i) s[i] += s[i - 1];
	ll ans = s[n] * 5 + (ll)n * X;
	for (int k = 1; k < n; ++k) {
		ll sum = (ll)k * X;
		for (int i = 1; (i - 1) * k < n; ++i) {
			sum += (s[min(i * k, n)] - s[(i - 1) * k]) * (i == 1 ? 5 : i * 2 + 1);
			if (sum >= ans) break;
		}
		ans = min(ans, sum);
	}
	ans += (ll)n * X;
	printf("%lld\n", ans);
	return 0;
}
