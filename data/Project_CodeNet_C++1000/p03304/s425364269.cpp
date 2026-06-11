#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	double n,m;
	ll d;
	
	cin >> n >> m >> d;
	double ans = 0;
	if(d==0)
	{
		ans = 1.0/n*(m-1);
	}
	else
	{
		ans = 2*(n-d)/n/n*(m-1);
	}
	printf("%.10lf\n",ans);
	return 0;
}
