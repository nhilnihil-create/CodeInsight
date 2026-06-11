#include<bits/stdc++.h>
using namespace std;
const int maxn=110000;
vector<int> oa,ob;
int n;
char s[maxn];
int fa[maxn];
int check()
{
	if(s[n]=='1') return 0;
	for(int i=1;i<=n-1;i++) 
	{
		if(s[i]==s[n-i]) continue;
		return 0;
	}
	if(s[1]=='0') return 0;
	return 1;
}
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	if(!check()) return printf("-1\n"),0;
	int root=n;
	for(int i=n-1;i>=1;i--) 
	{
		if(s[i]=='0') fa[i]=root;
		else fa[i]=root,root=i;
	}
	for(int i=1;i<=n-1;i++)
	{
		if(fa[i]==i) continue;
		printf("%d %d\n",i,fa[i]);
	}
	return 0;
}