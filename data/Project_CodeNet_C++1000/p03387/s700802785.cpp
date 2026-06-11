#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	
	int a1,b1,c1;
	a1=a%2;
	b1=b%2;
	c1=c%2;
	int st=0;
	    if(a1==b1&&b1==c1)
	    {
	    	st+=0;
		}
		else if(a1==b1)
		{
			a++;
			b++;
			st++;
		}
		else if(b1==c1)
		{
			c++;
			b++;
			st++;
		}
		else if(c1==a1)
		{
			a++;
			c++;
			st++;
		}
	int ma=max(a,max(b,c));
	st+=(ma-a)/2;
	st+=(ma-b)/2;
	st+=(ma-c)/2;
	cout<<st<<endl;
}