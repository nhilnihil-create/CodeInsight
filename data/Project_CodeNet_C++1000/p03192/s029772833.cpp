#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a,n=0;
	cin>>a;
	while(a>0)
	{
		if(a%10==2)
		{
			n++;
		}
		a=a/10;
	}
	cout<<n<<endl;
	return 0;
}
