#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int a,b,c,temp,flg=0;
	cin>>a>>b>>c;
	if(a>b)
	{
		temp=b;
		b=a;
		a=temp;
	}
	for(int i=a;i<=b;i++)
	{
		if(i==c)
		{
			flg=1;
			break;
		}
	}
	if(flg==1)	
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	return 0;
}