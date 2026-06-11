#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#define ll long long
#define inf 0x3f3f3f3f
#define maxn 200010
inline ll read()
{
	ll x=0; char c=getchar(),f=1;
	for(;c<'0'||'9'<c;c=getchar())if(c=='-')f=-1;
	for(;'0'<=c&&c<='9';c=getchar())x=x*10+c-'0';
	return x*f;
}
inline void write(ll x)
{
	static char buf[20];
	int len=0;
	if(x<0)putchar('-'),x=-x;
	for(;x;x/=10)buf[len++]=x%10+'0';
	if(!len)putchar('0');
	else while(len)putchar(buf[--len]);
}
inline void writesp(ll x){write(x); putchar(' ');}
inline void writeln(ll x){write(x); putchar('\n');}
const std::string dt[5][5]={{"","","LL","",""},{"","LD","L","LU",""},{"DD","D","LR","U","UU"},{"","RD","R","RU",""},{"","","RR","",""}};
int x[maxn],y[maxn];
int p[30],numx[30],numy[30];
std::string ans;
int n;
void solve(int dep,int& x,int& y)
{
	if(dep>=19)return;
	int tx=(x%3+3)%3,ty=(y%3+3)%3;
	x=(x-tx)/3; y=(y-ty)/3;
	if((tx+ty)&1){
		if(tx>ty)tx-=3,++x;
		else ty-=3,++y;
	}
	else if(tx==2&&ty==2){
		tx-=3; ++x;
		ty-=3; ++y;
	}
	numx[dep]=tx; numy[dep]=ty;
	solve(dep+1,x,y);
}
int main()
{
	n=read();
	int flag0=0,flag1=0;
	for(int i=1;i<=n;i++){
		x[i]=read(); y[i]=read();
		if((x[i]+y[i])&1)flag1=1;
		else flag0=1;
	}
	if(flag0&&flag1){
		puts("-1"); return 0;
	}
	p[0]=1;
	for(int i=1;i<20;i++)
		p[i]=p[i-1]*3;
	if(flag0){
		writeln(40);
		for(int i=0;i<=19;i++){
			writesp(p[i]);
			writesp(p[i]);
		}
		putchar('\n');
	}
	else{
		writeln(39);
		for(int i=0;i<=19;i++){
			writesp(p[i]);
			if(i<19)writesp(p[i]);
		}
		putchar('\n');
	}
	for(int i=1;i<=n;i++){
		solve(0,x[i],y[i]);
		// printf("%d %d\n",x[i],y[i]);
		// for(int j=0;j<19;j++)
		// 	printf("%d %d %d\n",j,numx[j],numy[j]);
		ans="";
		for(int j=0;j<19;j++)
			ans+=dt[numx[j]+2][numy[j]+2];
		ans+=dt[x[i]+2][y[i]+2];
		std::cout<<ans<<"\n";
	}
	return 0;
}