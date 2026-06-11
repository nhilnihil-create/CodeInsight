#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int a,b;
	cin>>a>>b;
	if(a<b)
	{
		swap(a,b);
	}
	if((a-1)>=b)
	{
		cout<<a+(a-1)<<endl;
	}
	else
	{
		cout<<a+b<<endl;
	}
	return 0;
}