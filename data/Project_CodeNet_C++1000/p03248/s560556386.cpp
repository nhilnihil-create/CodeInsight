#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define eps 1e-10
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

char s[maxn];
vector <int> ans[maxn];
int b[maxn],cnt;

int main()
{
	scanf("%s",s+1); int len=strlen(s+1),f=0;
	if(s[1]!='1'||s[len]!='0') f=1;
	for(int i=1;i<=len;i++) if(s[i]-'0'+s[len-i]-'0'==1) f=1;
	if(f==1) {puts("-1"); return 0;}
	int lst=2;
	b[++cnt]=1;
	printf("%d %d\n",2,1);
	for(int i=2;i<=len-1;i++)
	{
		if(s[i]=='1')
		{
			for(int j=lst+1;j<=i;j++) printf("%d %d\n",lst,j);
			printf("%d %d\n",lst,i+1); lst=i+1;
		}
	}
	//printf("%d %d\n",len,lst);
	return 0;
}