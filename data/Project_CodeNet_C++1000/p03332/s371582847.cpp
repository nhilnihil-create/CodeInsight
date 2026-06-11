#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof x)
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define outval(x) cerr<<#x" = "<<x<<endl
#define outtag(x) cerr<<"---------------"#x"---------------"<<endl
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
						For(_x,L,R)cerr<<a[_x]<<" ";cerr<<endl;
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector <int> vi;
typedef long double LD;
typedef pair <int,int> pii;
typedef pair <int,LL> piL;
LL read(){
	LL x=0,f=0;
	char ch=getchar();
	while (!isdigit(ch))
		f|=ch=='-',ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?-x:x;
}
const int N=300005,mod=998244353;
int Pow(int x,int y){
	int ans=1;
	for (;y;y>>=1,x=(LL)x*x%mod)
		if (y&1)
			ans=(LL)ans*x%mod;
	return ans;
}
void Add(int &x,int y){
	if ((x+=y)>=mod)
		x-=mod;
}
void Del(int &x,int y){
	if ((x-=y)<0)
		x+=mod;
}
int Add(int x){
	return x>=mod?x-mod:x;
}
int Del(int x){
	return x<0?x+mod:x;
}
int Fac[N],Inv[N];
void prework(){
	int n=N-1;
	for (int i=Fac[0]=1;i<=n;i++)
		Fac[i]=(LL)Fac[i-1]*i%mod;
	Inv[n]=Pow(Fac[n],mod-2);
	Fod(i,n,1)
		Inv[i-1]=(LL)Inv[i]*i%mod;
}
int C(int n,int m){
	if (m<0||m>n)
		return 0;
	return (LL)Fac[n]*Inv[m]%mod*Inv[n-m]%mod;
}
int n,a,b;
LL k;
int main(){
	prework();
	n=read(),a=read(),b=read(),k=read();
	int ans=0;
	For(i,0,n){
		if ((k-(LL)a*i)%b)
			continue;
		LL j=(k-(LL)a*i)/b;
		if (j<0||j>n)
			continue;
		Add(ans,(LL)C(n,i)*C(n,j)%mod);
	}
	cout<<ans<<endl;
	return 0;
}