#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll, int> M;
ll sum, ans;
int main()
{
	int n;
	scanf("%d", &n);
	M[sum] = 1;
	for(int i = 1; i <= n; ++i)
	{
		int val;
		scanf("%d", &val);
		sum += val;
		ans += M[sum];
		++M[sum];
	}
	printf("%lld\n", ans);
	return 0;
}
		
	 