#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include<ctime>
#include<map>
#include<bitset>
#include<set>
#define LL long long
#define mp(x,y) make_pair(x,y)
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;
inline int read()
{
	int f=1,x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int stack[20];
inline void write(int x)
{
	if(x<0){putchar('-');x=-x;}
    if(!x){putchar('0');return;}
    int top=0;
    while(x)stack[++top]=x%10,x/=10;
    while(top)putchar(stack[top--]+'0');
}
inline void pr1(int x){write(x);putchar(' ');}
inline void pr2(int x){write(x);putchar('\n');}
const int MAXN=300005;
int n,A,B;
int a[MAXN];
int main()
{
	n=read();A=read();B=read();
	int up1=n/A;if(n%A)up1++;
	int up2=n/B;if(n%B)up2++;
	if(A<up2||B<up1||A+B>n+1)return puts("-1"),0;
	for(int i=1;i<=B;i++)a[i]=B-i+1;
	for(int i=B+1,nxt=0,ls=1;i<=n;i=nxt+1)
	{
		if(ls+1+(n-i+1-B)>A)
		{
			nxt=i+B-1;
			for(int j=i,cnt=nxt;j<=nxt;j++)a[j]=cnt--;
			ls++;
		}
		else
		{
			nxt=n-(A-ls-1);
			for(int j=i,cnt=nxt;j<=nxt;j++)a[j]=cnt--;
			for(int j=nxt+1;j<=n;j++)a[j]=j;
			nxt=n;
		}
	}
	for(int i=1;i<=n;i++)pr1(a[i]);
	return 0;
}
