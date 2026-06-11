#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dbl;
int main()
{
	dbl n,k;
	cin>>n>>k;
	dbl ans=0;
	for(dbl i=1; i<=n; i++)
	{
		dbl temp=1/n;
		dbl score=i;
		while(score<k)
		{
			temp*=0.5;
			score*=2;
		}
		ans+=temp;
	}
	cout<<fixed<<setprecision(9)<<ans;
	return 0;

}