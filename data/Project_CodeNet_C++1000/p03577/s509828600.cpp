//#pragma GCC optimize(2)				//O2优化 
//#pragma GCC optimize(3)				//O3优化 
#include<bits/stdc++.h>
using namespace std;
#define INF 0x7fffffff
#define ME 0x7f
#define FO(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout)
#define fui(i,a,b,c) for(int i=(a);i<=(b);i+=(c))
#define fdi(i,a,b,c) for(int i=(a);i>=(b);i-=(c))
#define fel(i,a) for(register int i=hd[a];i;i=dg[i].nxt)
#define ll long long
#define MEM(a,b) memset(a,b,sizeof(a))
string s,s2;
template<class T>
inline T read(T &n){
	n=0;int t=1;double x=10;char ch;
	for(ch=getchar();!isdigit(ch)&&ch!='-';ch=getchar());(ch=='-')?t=-1:n=ch-'0';
	for(ch=getchar();isdigit(ch);ch=getchar()) n=n*10+ch-'0';
	if(ch=='.') for(ch=getchar();isdigit(ch);ch=getchar()) n+=(ch-'0')/x,x*=10;
	return (n*=t);
}
template<class T>
T write(T n){
	if(n<0) putchar('-'),n=-n;
	if(n>=10) write(n/10);putchar(n%10+'0');return n;
}
template<class T>
T writeln(T n){write(n);putchar('\n');return n;}
int main(){
	cin>>s;
	fui(i,0,s.size()-9,1)s2=s2+s[i];
	cout<<s2;
	return 0;
}