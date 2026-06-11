#include <bits/stdc++.h>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back
#define mset(x, y) memset(x, y, sizeof x)
#define mcpy(x, y) memcpy(x, y, sizeof x)
using namespace std;

typedef long long LL;
typedef pair <int, int> pii;

inline int Read()
{
	int x = 0, f = 1, c = getchar();
	for (; !isdigit(c); c = getchar())
		if (c == '-')
			f = -1;
	for (;  isdigit(c); c = getchar())
		x = x * 10 + c - '0';
	return x * f;
}

const int MAXN = 100005;

char s[MAXN];
int a[3];

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	scanf("%s", s);
	for (int i = 0; s[i]; i ++)
		a[s[i] - 'a'] ++;
	return puts(*max_element(a, a + 3) - *min_element(a, a + 3) <= 1 ? "YES" : "NO"), 0;
}
