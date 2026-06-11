#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int n,a,b;
	int max,min;

	cin>>n>>a>>b;

	if(a<b) max=a;
	else max=b;

	if((a+b)<=n) min=0;
	else min=(a+b)-n;

	cout<<max<<' '<<min<<endl;

	return 0;
}
