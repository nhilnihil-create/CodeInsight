#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define pa pair<int,int>
const int Maxn=100010;
const int inf=2147483647;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*f;
}
int mark[Maxn];
vector<int>h[Maxn];
int main()
{
	int t=0;
	for(int i=1;i<=3000;i++)
	{
		t+=i;
		if(t>100000)break;
		mark[t]=i;
	}
	int n=read();
	if(!mark[n])return puts("No"),0;
	puts("Yes");
	int u=mark[n]+1,cnt=0;
	for(int i=1;i<=u;i++)
		for(int j=i+1;j<=u;j++)++cnt,h[i].push_back(cnt),h[j].push_back(cnt);
	printf("%d\n",u);
	for(int i=1;i<=u;i++)
	{
		printf("%d ",h[i].size());
		for(int j=0;j<h[i].size();j++)printf("%d ",h[i][j]);
		puts("");
	}
}