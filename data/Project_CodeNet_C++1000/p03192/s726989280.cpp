#include<bits/stdc++.h>
using namespace std;
int a,ans;
int main()
{
	cin>>a;
	for(;a>0;a/=10)
	{
		if(a%10==2)  ans++;
	}
	cout<<ans;

	return 0;
}