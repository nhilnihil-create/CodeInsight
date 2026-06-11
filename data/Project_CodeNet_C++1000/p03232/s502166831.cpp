#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof x)
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fi first
#define se second
#define outval(x) cerr<<#x" = "<<x<<endl
#define outtag(x) cerr<<"-----------------"#x"-----------------\n"
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
                    For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
LL read(){
    LL x=0,f=0;
    char ch=getchar();
    while (!isdigit(ch))
        f=ch=='-',ch=getchar();
    while (isdigit(ch))
        x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return f?-x:x;
}
const int N=100005,mod=1e9+7;
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
	if (m>n||m<0)
		return 0;
	return (LL)Fac[n]*Inv[m]%mod*Inv[n-m]%mod;
}
int n;
int a[N];
int s[N];
int sum(int L,int R){
	return Del(s[R]-s[L-1]);
}
int main(){
	prework();
	n=read();
	For(i,1,n)
		a[i]=read();
	For(i,1,n)
		s[i]=Add(s[i-1]+a[i]);
	int ans=0;
	//[1..n]
	Add(ans,sum(1,n));
	//[1..i]
	For(i,1,n-1)
		Add(ans,(LL)sum(1,i)*Pow(i+1,mod-2)%mod);
	//[i..n]
	Fod(i,n,2)
		Add(ans,(LL)sum(i,n)*Pow(n-i+1+1,mod-2)%mod);
	//[a..b]
	int tmp=0;
	For(i,1,n-2){
		Add(tmp,(LL)a[i+1]*i%mod);
		Add(tmp,(LL)a[n-i]*i%mod);
		int len=n-1-i,p=(LL)Fac[2]*Fac[len]%mod*Inv[len+2]%mod;
		Add(ans,(LL)tmp*p%mod);
		Add(ans,(LL)i*sum(i+2,n-i-1)%mod*p%mod);
	}
	ans=(LL)ans*Fac[n]%mod;
	cout<<ans<<endl;
	return 0;
}