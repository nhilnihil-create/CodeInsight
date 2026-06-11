#include <bits/stdc++.h>
using namespace std;

#define N 200010
int h, w, n;
vector <int> v[N];

int main()
{
	while (scanf("%d%d", &h, &w) != EOF)
	{
		scanf("%d", &n); 
		int res = h; 
	    for (int i = 1; i <= h; ++i) v[i].clear(); 	
		for (int i = 1, x, y; i <= n; ++i)
		{
			scanf("%d%d", &x, &y);
			v[x].push_back(y);
		}
		int far = 1; 
		for (int i = 2; i <= h; ++i) 
		{
			if (v[i].empty()) 
			{
				++far;
				continue;
			}
			sort(v[i].begin(), v[i].end());
			if (v[i][0] <= far) 
			{
				res = i - 1;
				break;
			}
			bool flag = true; 
			for (auto it : v[i]) if (it == far + 1)
				flag = false;
			far += flag; 
		}
		printf("%d\n", res); 
	}
	return 0;
}
