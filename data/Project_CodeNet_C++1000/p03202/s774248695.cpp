#include<cstdio>
#define N 200005
using namespace std;
int read()
{
	int x=0;char ch=getchar();
	while (ch<'0'||ch>'9')ch=getchar();
	while (ch>='0'&&ch<='9')x=x*10+(ch^48),ch=getchar();
	return x;
}
int n,cnt,a[N],b[N],mul[25],w;
bool p;
struct stk{
	int pos,num,c;
}s[N];int top;
inline void Plus(int x){while (mul[s[x].c]<=s[x].num&&s[x].c<=w)++s[x].c;}
inline void Sub(int x){while (mul[s[x].c-1]>s[x].num)--s[x].c;}
void add(int x)
{
	++top;
	s[top].pos=a[x];
	s[top].num=b[x]-1;
	s[top].c=1;
	Plus(top);
}
bool check(int m)
{
	if (m<=1)return 0;
	mul[1]=m;
	for (w=1;mul[w]<=n/m;++w)mul[w+1]=mul[w]*m;
//	mul[++w]=n+1;
	top=0;
//	add(1);
	for (int i=1;i<=cnt;++i)
	{
		if (a[i]>a[i-1])add(i);
		else
		{
			while (a[i]<=s[top].pos-s[top].c&&top)--top;
			if (!top||s[top].pos<a[i])++b[i],add(i),--b[i];
			else
			{
				if (s[top].pos>a[i])
				{
					int l=s[top].pos-a[i];
					s[top].pos=a[i];
					s[top].num/=mul[l];
					s[top].c-=l;
				}
				s[top].num+=b[i];
				Plus(top);
			}
		}
		for (int j=top;j>1&&s[j].pos-s[j].c<s[j-1].pos;--j)
		{
			int l=s[j].pos-s[j-1].pos,v=s[j].num/mul[l];
			s[j].num-=v*mul[l];
			s[j].c=l;Sub(j);
			s[j-1].num+=v;
			Plus(j-1);
		}
		if (s[1].pos-s[1].c<0)return 0;
	}return 1;
}
int main()
{
	n=read();a[0]=-1;
	for (int i=1,x;i<=n;++i)
	{
		x=read();
		if (x<=a[cnt])p=1;
		if (x!=a[cnt])a[++cnt]=x;
		++b[cnt];
	}
	if (!p){puts("1");return 0;}
	int ans=n;
	for (int A=n-1;A;A>>=1)
	if (check(ans-((A+1)>>1)))ans-=(A+1)>>1;
	printf("%d\n",ans);
	return 0;
}