#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll N=305;
double dp[N][N][N],prob[N][N][N];
int main()
{
	ll n,i,j;
	cin >> n;
	ll arr[n];
	ll mini=LLONG_MAX;
	ll one=0,two=0,three=0;
	ll a=0,b=0,c=0;
	for(i=0;i<n;i++)
	{
		cin >> arr[i];
		if(arr[i]==3)
			c++;
		else if(arr[i]==2)
			b++;
		else
			a++;
	}
	prob[a][b][c]=1;
	for(three=n;three>=0;three--)
	{
		for(two=n;two>=0;two--)
		{
			for(one=n;one>=0;one--)
			{
				if(one+two+three > n || (one==0 && two==0 && three==0))
					continue;
				
				double pwaste=(double)(n-(one+two+three))/(double)n;
				double dp_waste = pwaste/(1-pwaste);
				dp[one][two][three]+=dp_waste * prob[one][two][three];
				if(one!=0)
				{
					double w=(double) one / (one+two+three);
					prob[one-1][two][three]+=prob[one][two][three]*w;
					dp[one-1][two][three]+=dp[one][two][three]*w;
				}
		
				if(two!=0)
				{
					double w=(double) two / (one+two+three);
					prob[one+1][two-1][three]+=prob[one][two][three]*w;
					dp[one+1][two-1][three]+=dp[one][two][three]*w;
				}
				
				if(three!=0)
				{
					double w=(double) three / (one+two+three);
					prob[one][two+1][three-1]+=prob[one][two][three]*w;
					dp[one][two+1][three-1]+=dp[one][two][three]*w;
				}
			}
		}
	}
	cout<<setprecision(12);
	cout<<(dp[0][0][0]+a+2*b+3*c)<<"\n";
	
}