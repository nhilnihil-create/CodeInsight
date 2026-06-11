#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int n, a[maxn], b[maxn];
vector<int> vec;
ll ans;
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d%d", &a[i], &b[i]);
		if(a[i] > b[i]) vec.push_back(b[i]);
		ans += a[i];
	}
	if(vec.empty())
	{
		puts("0");
		return 0;
	}
	printf("%lld\n", ans - *min_element(vec.begin(), vec.end()));
	return 0;
}