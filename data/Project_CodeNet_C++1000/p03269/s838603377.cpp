#include<cstdio>
#include<vector>
using namespace std;
int n, m;
vector<pair<pair<int,int>,int>> dap;
int main()
{
	int n;
	scanf("%d", &n);
	int ch = 0;
	n--;
	for (int i = 20; i >= 0; i--)
	{
		if (n&(1<<i))
		{
			ch = i;
			break;
		}
	}
	if (n == 1)
	{
		printf("2 2\n1 2 0\n1 2 1");
		return 0;
	}
	for (int i = 1; i <=ch; i++)
	{
		dap.push_back({ {i,i + 1},0 });
		dap.push_back({ { i,i + 1 },(1<<(i-1)) });
	}
	int x = 0;
	int prev = 1;
	for (int i = 1; i <= ch+1; i++)
	{
		if (n&(1 << (i - 1)))
		{
			dap.push_back({ {prev, ch + 1}, n - x });
			prev = i;
			x += (1 << (i - 1));
		}
	}
	printf("%d %d\n", ch + 1, dap.size());
	for (int i = 0; i < dap.size(); i++)
		printf("%d %d %d\n", dap[i].first.first, dap[i].first.second, dap[i].second);
}