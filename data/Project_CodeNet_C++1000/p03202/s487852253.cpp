#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
ll n;
vector<vector<int>> vt;
ll a[200010];
ll ch[300010];
ll up[300010];
int main()
{
	int cnt = 0;
	scanf("%lld", &n);
	vt.resize(n + 1);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	int update = 0;
	for (int i = 1; i < n; i++)
	{
		if (a[i - 1] < a[i]);
		else
			update = 1;
	}
	if (!update)
	{
		puts("1");
		return 0;
	}
	for (int i = 1; i < n; i++)
	{
		if (a[i - 1] < a[i]) {
			if (vt[cnt].size())
				cnt++;
		}
		else
		{
			if (a[i] >= 300000)continue;
			vt[cnt].push_back(a[i]);
		}
	}
	if (vt[cnt].size())
		cnt++;
	int dap = n;
	int left = 2;
	int right = n;
	while (left <= right)
	{
		memset(ch, 0, sizeof(ch));
		memset(up, -1, sizeof(up));
		int mid = (left + right) / 2;
		for (int i = 0; i < cnt; i++)
		{
			for (int y = 0; y < vt[i].size(); y++)
			{
				if (i)
				{
					if (vt[i][y] > vt[i - 1][vt[i - 1].size() - 1] && up[vt[i][y]] != i)
					{
						ch[vt[i][y]] = 0;
						up[vt[i][y]] = i;
					}
				}
				ch[vt[i][y]]++;
				for (int z = vt[i][y]; z >= 1; z--)
				{
					if (i) {
						if (z - 1 > vt[i - 1][vt[i - 1].size() - 1] && up[z - 1] != i)
						{
							ch[z - 1] = 0;
							up[z - 1] = i;
						}
					}
					if (ch[z] / mid) {
						ch[z - 1] = ch[z - 1] + (ch[z] / mid);
					}
					else
						break;
					ch[z] = ch[z]%mid;
				}
			}
		}
		if (ch[0])
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
			dap = min(dap, mid);
		}
	}
	printf("%d", dap);
}