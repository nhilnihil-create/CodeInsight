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
inline void write(LL x)
{
	if(x<0){putchar('-');x=-x;}
    if(!x){putchar('0');return;}
    int top=0;
    while(x)stack[++top]=x%10,x/=10;
    while(top)putchar(stack[top--]+'0');
}
inline void pr1(int x){write(x);putchar(' ');}
inline void pr2(LL x){write(x);putchar('\n');}
int A,B;
int main()
{
	int T=read();while(T--)
	{
		A=read();B=read();
		if(A>B)swap(A,B);
		if(A==B||A+1==B){pr2(2*A-2);continue;}
		LL C=(LL)sqrt((long double)A*B-1),ans=2*C;
		if(C*(C+1)>=1LL*A*B)ans-=2;
		else ans-=1;
		pr2(ans);
	}
	return 0;
}

