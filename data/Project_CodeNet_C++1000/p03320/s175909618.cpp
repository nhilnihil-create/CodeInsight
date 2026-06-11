#include<cstdio>
#include<vector>
#include<algorithm>


using namespace std;
using ll=long long;
using vll=vector<ll>;
using vvll=vector<vll>;
using vi=vector<int>;
using vvi=vector<vi>;


double sunuke(ll x)
{
	int s=0;
	ll y;

	for(y=x;y>0;y/=10)
	{
		s+=y%10;
	}
	return (double)x/s;
}


int main(void)
{
	int k;

	while(scanf("%d", &k)==1)
	{
		ll add=1;
		ll t=1;

		for(int i=0;i<k;i++)
		{
			printf("%lld\n", t, add);
			ll tn=t+add;
			if(sunuke(tn)>sunuke(tn+add))
			{
				add*=10;
				tn=t+add;
			}
			t=tn;
		}
	}

	return 0;
}
