#include<bits/stdc++.h>
using namespace std;

double dp[301][301][301];
double sushi(int n,int one,int two,int three)
{
	if(one<0 || two<0 || three<0)
		return 0;
	if(one==0  && two==0 && three==0)
		return 0;
	if(dp[one][two][three]>0)
		return dp[one][two][three];

	double a1=n+(one*sushi(n,one-1,two,three))+
				   (two*sushi(n,one+1,two-1,three))
				   +(three*sushi(n,one,two+1,three-1));
	
	dp[one][two][three]=a1/(one+two+three);
	return dp[one][two][three];
}

int main()
{
	memset(dp,-1,sizeof(dp));
	int n;
	cin>>n;
	int one=0,two=0,three=0;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		// cout<<x<<endl;
		if(x==1)
			one++;
		else if(x==2)
			two++;
		else if(x==3)
			three++;
	}
	// cout<<one<<two<<three<<endl;
	cout<<fixed<<setprecision(10)<<sushi(n,one,two,three);

}