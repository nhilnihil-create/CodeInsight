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
const int N=200005;
const LL INF=1e18;
int n,X;
int a[N];
LL f(int x){
	LL ans=(LL)X*x;
	int c=0,v=5,t=2;
	Fod(i,n,1){
		ans+=(LL)a[i]*v;
		if ((++c)==x)
			c=0,v=t*2+1,t++;
	}
	return ans;
}
int main(){
	n=read(),X=read();
	For(i,1,n)
		a[i]=read();
	LL ans=INF;
	int L=1,R=n;
	while (L+6<=R){
		int Lmid=(L*2+R)/3;
		int Rmid=(R*2+L)/3;
		LL fL=f(Lmid);
		LL fR=f(Rmid);
		ans=min(ans,fL);
		ans=min(ans,fR);
		if (fL>fR)
			L=Lmid;
		else
			R=Rmid;
	}
	For(i,L,R)
		ans=min(ans,f(i));
	ans+=(LL)X*n;
	cout<<ans<<endl;
    return 0;
}