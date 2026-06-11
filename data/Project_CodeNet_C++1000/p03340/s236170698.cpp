#include<algorithm>
#include<stdio.h>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<map>
#include<math.h>
#define ll long long
using namespace std;
double p = 3.1415926535897932384626433832795028841971693993751058209749445923078164;
/**/
int main()
{
	int n;
	cin>>n;
	ll num[200005];
	for(int i=0;i<n;i++)
		cin>>num[i];
	ll sum1=0,sum2=0,ans=0;
	int r=0;
	for(int l=0;l<n;l++)
	{
		while((sum1^num[r])==(sum2+num[r])&&r<n)
		{
			sum1 ^= num[r];
			sum2 += num[r];
			r++;
		}
		ans += (r-l);
		//printf("%lld %lld\n",sum1,sum2);
		sum1 ^= num[l];
		sum2 -= num[l];
		//printf("%lld %lld\n",sum1,sum2);
	}
	cout<<ans<<endl;
	return 0;
}
