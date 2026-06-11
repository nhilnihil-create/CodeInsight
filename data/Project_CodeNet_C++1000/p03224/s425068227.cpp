#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define MP make_pair
#define N 100010

int c[N], vis[N];

int main()
{
	/*s1 + s2 - 1 + s3 - 2 +...
	s1 + s2 +...sk - (0 + 1 + 2 + ...k - 1) = n
	0 + 1 + ... k - 1 = n
	k * (k - 1) / 2 = n*/
	
	int n;
	scanf("%d", &n);
	int k = 1;
	while (k * (k - 1) / 2 < n) ++k;
	if (k * (k - 1) / 2 > n) return puts("No"), 0;
	puts("Yes");
	//k * (k - 1) = 2 * n
	/*n = 6, k = 4
	1 2 3
	1     4 5
      2   4   6
        3   5 6
	n = 10, k = 5
	1 2 3 4
	1       5 6 7
	  2     5     8 9
	    3     6   8   10 
		  4     7   9 10 */
    printf("%d\n", k);
    for (int i = 1; i <= k; ++i)
    {
    	printf("%d", k - 1);
    	int cnt = k - 1;
    	vector<int> lis;
    	for (int j = 1; j <= n && cnt; ++j)
    	{
    		if (c[j] == -1) continue;
    		if (c[j] == 0)
    		{
    			c[j] = i;
    			--cnt;
    			printf(" %d", j); 
    		}
    		else if (c[j])
			{
				if (vis[c[j]]) continue;
				vis[c[j]] = i;
				lis.push_back(c[j]);
				--cnt;
				printf(" %d", j);
				c[j] = -1;
			}
    	}
    	for (auto v: lis) vis[v] = 0;
    	puts("");
    }
	
	
	return 0;
}