#include <cstdio>
#include <algorithm>
#include <queue>
#define file(x) freopen(#x".in", "r", stdin), freopen(#x".out", "w", stdout)

inline int read()
{
	int data = 0, w = 1; char ch = getchar();
	while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
	if (ch == '-') w = -1, ch = getchar();
	while (ch >= '0' && ch <= '9') data = data * 10 + (ch ^ 48), ch = getchar();
	return data * w;
}

const int N(1e5 + 10);
std::deque<int> Q;
int K, f[N], vis[N];

int main()
{
	K = read(), Q.push_back(1);
	for (int i = 0; i < K; i++) f[i] = 1e9; f[1] = 1;
	while (!Q.empty())
	{
		int x = Q.front(), y; Q.pop_front();
		if (vis[x]) continue; vis[x] = 1;
		y = x * 10 % K, f[y] = std::min(f[y], f[x]), Q.push_front(y);
		y = (x + 1) % K, f[y] = std::min(f[y], f[x] + 1), Q.push_back(y);
	}
	printf("%d\n", f[0]);
	return 0;
}
