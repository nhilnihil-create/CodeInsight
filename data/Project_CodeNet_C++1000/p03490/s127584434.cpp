#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
#include<bitset>
using namespace std;
template<typename __T>
inline void read(__T &x)
{
    x=0;
    int f=1;char c=getchar();
    while(!isdigit(c)){if(c=='-')	f=-1;c=getchar();}
    while(isdigit(c))	{x=x*10+c-'0';c=getchar();}
    x*=f;
}
template<typename T>
T rabs(T x)
{
	return x>0?x:-x;
}
vector<int>cc[2];
int o=0;
int n;
char str[8005];
int tx,ty;
int sum1,sum2;
bitset<8005>dp1;
bitset<8005>dp2;
int main()
{
	scanf("%s",str);
	n=strlen(str);
	read(tx);
	read(ty);
	str[n]='T';
	n++;
	str[n]=0;
	int las=-1;
	for(int i=0;i<n;i++)
	{
		if(str[i]=='T')
		{
			if(las!=-1)
				cc[o].push_back(i-las-1);
			else
				tx-=i;
			las=i;
			o=!o;
		}
	}
	int sz1=cc[0].size();
	int sz2=cc[1].size();
	tx=rabs(tx);
	ty=rabs(ty);
	for(int i=0;i<sz1;i++)
		sum1+=cc[0][i];
	for(int i=0;i<sz2;i++)
		sum2+=cc[1][i];
	if((sum1%2!=tx%2) || (sum2%2!=ty%2) || tx>sum1 || ty>sum2)
	{
		printf("No\n");
		return 0;
	}
	tx=(tx+sum1)/2;
	ty=(ty+sum2)/2;
	dp1[0]=1;
	dp2[0]=1;
	for(int i=0;i<sz1;i++)
		dp1|=(dp1<<cc[0][i]);
	for(int i=0;i<sz2;i++)
		dp2|=(dp2<<cc[1][i]);
	if(dp1[tx] && dp2[ty])
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}