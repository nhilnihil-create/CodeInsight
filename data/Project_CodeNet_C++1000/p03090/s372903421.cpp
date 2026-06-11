#include<cstdio>
#include<vector>
using namespace std;
int n;
int main()
{
	scanf("%d", &n);
	int x = (n & 1) ? n : (n + 1);
	vector<pair<int, int>> edges;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			if (i + j != x)
			{
				edges.push_back(make_pair(i, j));
			}
		}
	}
	printf("%d\n", edges.size());
	for (auto& p : edges) printf("%d %d\n", p.first, p.second);
	return 0;
}
