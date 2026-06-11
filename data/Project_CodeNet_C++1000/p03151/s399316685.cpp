#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int n;
ll a[100100], b[100100];
ll atot, btot;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
		atot += a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &b[i]);
		btot += b[i];
	}
	if (atot < btot)
	{
		printf("-1\n");
		return 0;
	}
	int ans = 0;
	ll diff = 0;
	vector<ll> v;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] < b[i])
		{
			diff += b[i] - a[i];
			ans++;
		}
		else if (a[i] > b[i])
		{
			v.push_back(a[i] - b[i]);
		}
	}
	sort(v.begin(), v.end());
	for (int i = v.size() - 1; i >= 0 && diff>0; i--)
	{
		diff -= v[i];
		ans++;
	}
	printf("%d\n", ans);
	return 0;
}
