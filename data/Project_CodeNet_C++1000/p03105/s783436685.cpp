#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	if((a*c)<=b)
	{
		cout<<c<<endl;
	}
	else
	{
		cout<<b/a<<endl;
	}
	return 0;
}