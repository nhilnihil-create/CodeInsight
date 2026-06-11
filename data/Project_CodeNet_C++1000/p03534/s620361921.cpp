#include<queue>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
inline void read(int &x)
{
	x=0;
	int p=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')p=-1;c=getchar();}
	while(isdigit(c)) {x=(x<<1)+(x<<3)+(c^'0');c=getchar();}
	x*=p;
}
char s[101000];
int tot[5];
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%s",s+1);
	int len=strlen(s+1);
	for(int i=1;i<=len;i++)
		tot[s[i]-'a'+1]++;
	int minn=min(tot[1],min(tot[2],tot[3]));
	tot[1]-=minn;tot[2]-=minn;tot[3]-=minn;
	if(tot[1]==0)
	{
		if(tot[2]>=2||tot[3]>=2)return puts("NO"),0;
		return puts("YES"),0;
	}
	else if(tot[2]==0)
	{
		if(tot[1]>=2||tot[3]>=2)return puts("NO"),0;
		return puts("YES"),0;
	}
	else if(tot[3]==0)
	{
		if(tot[1]>=2||tot[2]>=2)return puts("NO"),0;
		return puts("YES"),0;
	}
	return 0;
}