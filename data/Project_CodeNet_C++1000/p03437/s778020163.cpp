#include<iostream>
using namespace std;
int main()
{
	long long x,y;
	cin>>x>>y;
	long long ans = x*y;
	ans = ans - x;
	if(ans%y)
	{
		cout<<ans<<endl;
	}
	else
	{
		ans=-1;
		cout<<ans<<endl;
	}
}