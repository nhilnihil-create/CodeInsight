#include<bits/stdc++.h> 
using namespace std;
double f(long long x)
{
	long long sum=0,ans=x;
	while(x)
	{
		sum+=x%10;
		x/=10;
	}
	return 1.0*ans/sum;
}
int main()
{
	long long k,t=0,ans=0,x=1;
	cin>>k;
	while(t<k)
	{
		if(ans/x%10!=9)
		{
			ans+=x;
			cout<<ans<<endl;
			t++;
		}
		else
		{
			if(f(ans+x)>f(ans+10*x))
				x*=10;
			ans+=x;
			cout<<ans<<endl;
			t++;
		}
	}
	return 0;
}