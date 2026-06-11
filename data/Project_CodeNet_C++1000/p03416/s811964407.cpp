#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int a,b,i,cnt=0,n,m,c;
	cin>>a>>b;
	for(i=a;i<=b;i++)
	{
		m=i;
		n=i;
		c=0;
		while(n>0)
		{
			c=(c*10)+(n%10);
			n=n/10;
		}
		if(m-c==0)
		cnt++;
	}
	cout<<cnt<<endl;

	return 0;
}