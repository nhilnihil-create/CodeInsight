#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int a,b,p=0,c=0;
	cin>>a>>b;
	for(int i=a;i<=b;i++)
	{
		int x=i;
		while(x>0)
		{
			p=(p*10)+(x%10);
			x/=10;
		}
		if(p==i)
		{
			c++;
		}
		p=0;
	}
	cout<<c<<endl;
	return 0;
}