#include <iostream>
#include <cstdio>
using namespace std;
int ans,a[100005],r;
string str;
int main()
{
	cin>>str;
	for(int i=0;str[i]!='\0';i++)
	{
		a[++r]=(str[i]-'0');
		while(r>1&&a[r]+a[r-1]==1)
		{
			ans+=2;
			r-=2;
		}
//		cout<<r<<' ';
	}
	cout<<ans;
	return 0;
}
