#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;
double ans;
int main()
{
	int n,k; scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
	{
		int p=i; double t=1.0/n;
		while(p<k) p*=2,t*=0.5;
		ans+=t;
	}
	cout<<fixed<<setprecision(12)<<ans<<endl;
	return 0;
}