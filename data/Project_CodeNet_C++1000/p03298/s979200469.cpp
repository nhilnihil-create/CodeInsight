#include<iostream>
#include<cstdio>
#include<cstring>
#include<map> 
using namespace std;
typedef long long ll;
int n;
char s[45];
typedef pair<string,string> P;
map<P,ll>num;
ll ans;
string l,r;//l从左到右 r从右到左 
int main()
{
	scanf("%d",&n);
	scanf("%s",s);
	for(int i=0;i<(1<<n);++i)
	{
		l="",r=""; 
		for(int j=0;j<n;++j)
		{
			if(i>>j&1)l+=s[j];
			else r+=s[j];
		}
		num[P(l,r)]++;
	} 
	for(int i=0;i<(1<<n);++i)
	{
		l="",r="";
		for(int j=n-1;j>=0;--j)
		{
			if(i>>j&1)l+=s[n+j];
			else r+=s[n+j];
		}
		ans+=num[P(r,l)];
	}
	printf("%lld\n",ans);
} 