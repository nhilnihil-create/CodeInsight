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
const int MAXN=20;
const int MAXMASK=(1<<18);
int n,mx[MAXMASK][2],a[MAXMASK],g[5];
void down(int x,int y)
{
	g[1]=mx[x][0];g[2]=mx[x][1];
	g[3]=mx[y][0];g[4]=mx[y][1];
	sort(g+1,g+1+4);
	mx[x][0]=g[4];mx[x][1]=g[3];
}
int bin[25];
int main()
{
	bin[0]=1;for(int i=1;i<=20;i++)bin[i]=bin[i-1]<<1;
	n=read();
	for(int i=0;i<bin[n];i++)a[i]=mx[i][0]=read();
	for(int i=n-1;i>=0;i--)
		for(int j=bin[n]-1;j>=0;j--)if(!(j&bin[i]))down(j|bin[i],j);
	int sum=0;
	for(int i=1;i<bin[n];i++)pr2(sum=max(sum,mx[i][0]+mx[i][1]));
	return 0;
}
