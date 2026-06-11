/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#include<bits/stdc++.h>
#define ll long long
#define inf 1000000000000000000
#define mod 1000000007
#define put putchar('\n')
#define F(i,a,b) for (int i=(a);i<=(b);i++)
#define D(i,a,b) for (int i=(a);i>=(b);i--)
#define go(i,t) for (int i=head[t];i;i=Next[i])
#define sqr(x) ((x)*(x))
#define re register
#define mp make_pair
#define fi first
#define se second
#define pa pair<int,int>
#define pb push_back
#define be begin()
#define en end()
#define ret return puts("-1"),0;
#define N 500055
#define int ll
using namespace std;
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read(){char c=getchar();int tot=1;while ((c<'0'|| c>'9')&&c!='-') c=getchar();if (c=='-'){tot=-1;c=getchar();}
int sum=0;while (c>='0'&&c<='9'){sum=sum*10+c-'0';c=getchar();}return sum*tot;}
inline void wr(int x){if (x<0) {putchar('-');wr(-x);return;}if(x>=10)wr(x/10);putchar(x%10+'0');}
inline void wrn(int x){wr(x);put;}inline void wri(int x){wr(x);putchar(' ');}
inline void wrn(int x,int y){wri(x);wrn(y);}inline void wrn(int a,int b,int c){wri(a);wrn(b,c);}
int a[N],n,m,x1,ans;
int check(int x){
	int num=0,d=1,sum=0;
	D(i,n,1){
		num++;
		if (d==1) sum+=5*a[i]+x1;
		else sum+=a[i]*((d+1)*(d+1)-d*d);
		if (num==x) num=0,d++;
	}
	return sum;
}
signed main(){
	n=read();x1=read();
	F(i,1,n) a[i]=read();
	int l=1,r=n;
	while (r-l>3){
		int mid1=l+(r-l)/3,mid2=r-(r-l)/3;
		if (check(mid1)>check(mid2)) l=mid1;
		else r=mid2;
	}
	ans=inf;
	F(i,max(1LL,l-4),min(n,l+4)){
		ans=min(ans,check(i));
	}
	wrn(ans+n*x1);
	return 0;
}