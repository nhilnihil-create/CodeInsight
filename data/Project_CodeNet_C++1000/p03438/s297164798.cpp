#include<bits/stdc++.h>
#define inf ((1<<30)-1)
#define linf ((1<<62)ll-1)
#define LL long long
#define F(i,a,b,c) for(register int i=(a);(b);i=(c))
#define Fu(i,a,b) for(register int i=(a);i<=(b);++i)
#define Fd(i,a,b) for(register int i=(a);i>=(b);--i)
#define Fn(i,a) for(register int i=las[(a)];i;i=nex[i])
#define COND(c) (isprint(c))
int Fl,Pn,SI=100;char mch=' ',ch,Bf[21];
void chin(char&c){while(!COND(c=getchar()));}
template<typename t>void in(t&a){a=0;ch=getchar();Fl=1;while(((ch<'0')||(ch>'9'))&&ch!=EOF)Fl=(ch=='-')?-Fl:Fl,ch=getchar();while((ch>='0')&&(ch<='9'))a=a*10+ch-'0',ch=getchar();a*=Fl;}template<typename t>void out(t a){if(a<0)putchar('-'),a=-a;if(a==0)putchar('0');while(a)Bf[++Pn]=a%10+'0',a/=10;while(Pn)putchar(Bf[Pn]),--Pn;putchar(mch);}
template<typename t,typename ...ARGS>void in(t&a,ARGS&...args){in(a);in(args...);}
template<typename t,typename ...ARGS>void out(t a,ARGS... args){out(a);out(args...);}
using namespace std;
int a[10001],b,n;LL s1,s2;
int main()
{
	in(n);
	Fu(i,1,n)in(a[i]);
	Fu(i,1,n)
	{
		in(b);
		if(a[i]>b)s1+=(a[i]-b);
		else s2+=(b-a[i])/2; 
	}
	if(s1<=s2)cout<<"Yes\n";
	else cout<<"No\n";
	return 0;
}
//BY Segment_Tree_Juruo (2020严誉沣)
