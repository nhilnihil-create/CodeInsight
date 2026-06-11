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

const int INF = 0x3f3f3f3f, N = 100003, M = N << 1;

int n, fa[N];
char s[N];
bool vis[N];

int main()
{
	//File("");
	scanf("%s", s + 1);
	n = strlen(s + 1);
	if (s[n] == '1' || s[1] == '0' || s[n - 1] == '0') {puts("-1"); return 0;}
	for (int i = 2; i < n - 1; i+=1)
		if (s[i] == '1' && s[n - i] == '0') {puts("-1"); return 0;}
	int nowfa = 2, nowson = 1;
	vis[1] = vis[2] = true;
	fa[1] = 2;
	for (int i = 2; i < n; i+=1)
	{
		if (s[i] == '0')
		{
			while (vis[nowson]) ++nowson;
			fa[nowson] = nowfa;
			vis[nowson] = vis[nowfa] = true;
		}
		else
		{
			nowson = nowfa;
			while (vis[nowfa]) ++nowfa;
			fa[nowson] = nowfa;
			vis[nowson] = vis[nowfa] = true;
		}
	}
	int id = 0;
	for (int i = 1; i <= n; i+=1) if (fa[i] == 0) {id = i; break;}
	for (int i = 1; i <= n; i+=1)
		if (i != id)
			printf("%d %d\n", i, fa[i]);
	return 0;
}
