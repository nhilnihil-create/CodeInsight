#include<bits/stdc++.h>
using namespace std;

vector<double> v;

main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		double a;
		scanf("%lf",&a);
		v.push_back(a);
	}
	sort(v.begin(),v.end());
	double wanna=v[n-1]/2;
	double ans=v[0];
	//prijntf("%ll");
	for(int i=0;i<n-1;i++)
	{
		if(abs(ans-wanna)>abs(v[i]-wanna))ans=v[i];
	}
	printf("%.0lf %.0lf\n",v[n-1],ans);
}