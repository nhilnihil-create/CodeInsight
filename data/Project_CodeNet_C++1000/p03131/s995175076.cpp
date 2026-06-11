#include <bits/stdc++.h>
#define DEBUG fprintf(stderr, "Passing [%s] line %d\n", __FUNCTION__, __LINE__)
#define File(x) freopen(x".in","r",stdin); freopen(x".out","w",stdout)

using namespace std;

typedef long long LL;
typedef pair <int, int> PII;
typedef pair <int, PII> PIII;

template <typename T>
inline T gi()
{
	T f = 1, x = 0; char c = getchar();
	while (c < '0' || c > '9') {if (c == '-') f = -1; c = getchar();}
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return f * x;
}

const int INF = 0x3f3f3f3f, N = 200003, M = N << 1;

LL k, a, b;

int main()
{
	//File("");
	k = gi <LL> (), a = gi <LL> (), b = gi <LL> ();
	if (a >= b) cout << k + 1 << endl;
	else
	{
		if (k <= a) {cout << k + 1 << endl; return 0;}
		LL sum = k + 1;
		k -= a + 1;
		LL ans = b;
		int now = k / 2, d = k % 2;
		ans += now * (b - a);
		if (d) ++ans;
		cout << max(sum, ans) << endl;
	}
	return 0;
}
