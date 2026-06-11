#include<iostream>
#include<string>
#include<string.h>
#include<stdio.h>
#include<algorithm>
#include<map>
using namespace std;
map<pair <string,string>,int> f;
int main()
{
	int n;
	scanf("%d",&n);
	string st;
	cin >> st;
	int i,j;
	for (i=0;i<(1<<n);i++)
	{
		string s1="",s2="";
		for (j=0;j<n;j++)
		    if (i&(1<<j)) s1+=st[j];
		    else s2+=st[j];
		f[make_pair(s1,s2)]++;
	}
	
	long long ans=0;
	for (i=0;i<(1<<n);i++)
	{
		string s1="",s2="";
		for (j=n-1;j>=0;j--)
		    if (i&(1<<j)) s2+=st[j+n];
		    else s1+=st[j+n];
		ans+=f[make_pair(s1,s2)];
	}
	printf("%lld",ans);
	return 0;
}