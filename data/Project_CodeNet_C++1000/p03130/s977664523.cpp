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

int d[5];

int main()
{
	//File("");
	for (int i = 1; i <= 3; i+=1) ++d[gi <int> ()], ++d[gi <int> ()];
	int c1 = 0, c2 = 0;
	for (int i = 1; i <= 4; i+=1) if (d[i] == 2) ++c2; else if (d[i] == 1) ++c1;
	if (c1 == 2 && c2 == 2) puts("YES");
	else puts("NO");
	return 0;
}
