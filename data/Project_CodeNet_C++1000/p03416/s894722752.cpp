#include<bits/stdc++.h>
#include<sstream>
using namespace std;
int main()
{
	long long int a,b,i,n,flag=1,m,d,j,count=0;
	cin>>a>>b;
	for(i=a;i<=b;i++)
	{

	n=i;
	ostringstream str1;
	str1<<n;
	string s=str1.str();
	m=s.length();
	d=m/2;
	for(j=0;j<d;j++)
	{
		if(s[j]!=s[m-1-j])
		{
			flag=0;
			break;
		}
	}
	if(flag==1)
	{
		count++;
	}
	flag=1;
}
cout<<count;
	
}