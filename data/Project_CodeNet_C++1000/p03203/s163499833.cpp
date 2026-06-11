#include<cstdio>
#include<vector>
#include<algorithm>


using namespace std;
using vi=vector<int>;
using vvi=vector<vi>;
using ll=long long;
using vll=vector<ll>;


void min_u(int&m, int v)
{
	if(m>v) m=v;
}


int main(void)
{
	int h, w, n;

	while(scanf("%d%d%d", &h, &w, &n)==3)
	{
		vll b(n);
		int ans=h;

		for(int i=0;i<n;i++)
		{
			int x, y;

			scanf("%d%d", &x, &y);
			ll p=x*1000000LL+y;
			b[i]=p;
		}
		sort(b.begin(), b.end());
		int sx=1, sy=1;
		for(int i=0;i<n;i++)
		{
			int x=b[i]/1000000;
			int y=b[i]%1000000;

			if((x-sx)>(y-sy))
			{
				ans=x-1;
				break;
			}
			if((x-sx)==(y-sy))
			{
				sx=x;
				sy=y-1;
			}
		}

		printf("%d\n", ans);
	}

	return 0;
}
