
#include<bits/stdc++.h>
using namespace std;

int main ()
{
	typedef int l;
	int a,b,c,d;  cin>>a>>b>>c>>d;
	
	l s1=a+c;
	l s2=a+d;
	l s3=b+c;
	l s4=b+d;
	
	cout<<min(s1,min(s2,min(s3,s4)));
	
	


}
