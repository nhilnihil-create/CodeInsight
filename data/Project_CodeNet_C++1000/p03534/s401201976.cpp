//by sdfzchy
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int inf=(1<<30),N=100010,mod=1e9+7;
int n,m;
inline int in()
{
	char tmp=getchar();
	int res=0,f=1;
	while((tmp<'0'||tmp>'9')&&tmp!='-')tmp=getchar();
	if(tmp=='-') f=-1,tmp=getchar();
	while(tmp>='0'&&tmp<='9')	res=(res<<1)+(res<<3)+(tmp^48),tmp=getchar();
	return res*f;
}
char s[N];
int cnt[4],mn=inf,mx=-inf;
int main()
{
//	freopen("in.in","r",stdin);
//	freopen("out.out","w",stdout);
	scanf("%s",s);
	int len=strlen(s);
	for(int i=0;i<len;i++) cnt[s[i]-'a']++;
	for(int i=0;i<3;i++) mn=min(mn,cnt[i]),mx=max(mx,cnt[i]);
	if(mx-mn<=1) puts("YES");
	else puts("NO");
	return 0;
}
