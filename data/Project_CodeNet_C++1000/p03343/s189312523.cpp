#include <bits/stdc++.h>
using namespace std;
#define lowbit(x) (x & (-x))
#define mp(a, b) make_pair(a, b)
const int maxn = 2000 + 10;
typedef pair<int, int> pii;
int n, k, q, ans = 2e9;
vector<pii> b;
int a[maxn], C[maxn];
void add(int x)
{
	for(int i = x; i < maxn; i += lowbit(i))
		++C[i];
}
int sum(int x)
{
	int ret = 0;
	for(int i = x; i; i -= lowbit(i))
		ret += C[i];
	return ret;
}
bool solve(int now)
{
	memset(C, 0, sizeof(C));
	pii x = b[now];
	int val = x.first, pos = x.second;
	set<int> S;
	S.insert(0); S.insert(n + 1);
	for(int i = 1; i <= n; ++i)
		if(a[i] < val)
			S.insert(i);
	int cnt = 0;
	while(cnt < q && now < n)
	{
		auto it = S.upper_bound(pos);
		int r = *it;
		int l = *(--it);
		//	if(now == 0) cout << pos << ' ' << l << ' ' << r << endl;
		if(r - 1 - l - (sum(r - 1) - sum(l)) >= k)
		{
			++cnt;
			add(pos);
		}
		++now;
		val = b[now].first, pos = b[now].second;
	}
	if(cnt == q)
	{
		ans = min(ans, b[now - 1].first - x.first);
		return 1;
	}
	else
		return 0;
}
int main()
{
	scanf("%d%d%d", &n, &k, &q);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]);
		b.push_back(mp(a[i], i));
	}
	sort(b.begin(), b.end());
	for(int i = 0; i < n; ++i)
		if(!solve(i))
			break;
	printf("%d\n", ans);
	return 0;
}
