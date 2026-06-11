#include<iostream>
#include<set>
#include<map>
#include<unordered_set>
#include<cmath>
#include<algorithm>
using namespace std;
#include<vector>
#define int long long int
#define mod 1000000007
int32_t main()
{
	int n,k;
	cin>>n>>k;
	int prefix[n+1][k+1];
	int value[n+1][k+1];
	int i,j;
	i=n;
	for(j=0;j<=k;j++)
	{
		prefix[n][j]=1;
	}
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=k;j++)
		{
			value[i][j]=0;
		}
	}
	int arr[n];
	for(i=0;i<n;i++)
	   cin>>arr[i];
	for(j=n-1;j>=0;j--)
	{
		for(i=0;i<=k;i++)
		{
			int val=arr[j];
			int start=i-val;
			int end=i;
			start=max(0LL,start);
			int here=prefix[j+1][end];
			if(start>=1)
			{
				here-=prefix[j+1][start-1];
			}
			here=here%mod;
			if(here<0)
			   here+=mod;
			value[j][i]=here;
		}
		prefix[j][0]=value[j][0];
		for(i=1;i<=k;i++)
		{
			prefix[j][i]=value[j][i]+prefix[j][i-1];
			prefix[j][i]%=mod;
		}
	}
	int answer=value[0][k];
	answer%=mod;
	if(answer<0)
	   answer+=mod;
	cout<<answer<<endl;
}

