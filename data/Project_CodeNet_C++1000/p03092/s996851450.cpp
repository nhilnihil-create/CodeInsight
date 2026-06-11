/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#include<bits/stdc++.h>
#define ll long long
#define inf 100000000000005
#define mod 1000000007
#define put putchar('\n')
#define F(i,a,b) for (int i=(a);i<=(b);i++)
#define D(i,a,b) for (int i=(a);i>=(b);i--)
#define R(i,a,b) for (int i=(a);i<(b);i++)
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
#define int ll
#define N 5055
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
int n,m,ans,A,B,sum[N][N],f[N],p[N];
inline void cm(int &x,int k){x=(k<x)?k:x;}
signed main(){
	n=read();A=read();B=read();
	F(i,1,n){
		p[i]=read();
		F(j,1,n) sum[i][j]=sum[i-1][j];F(j,p[i],n) sum[i][j]++;
	}
	ans=inf;
	F(i,1,n){
		f[p[i]]=(p[i]-1)*B;
		F(j,1,i-1){
			if (p[j]>p[i]) continue;
			int t=p[j],p1=(sum[j][p[i]]-sum[j][t]);
			cm(f[p[i]],f[t]+A*p1+B*(p[i]-t-p1-1));
		}
		int p1=sum[i][n]-sum[i][p[i]];
		cm(ans,f[p[i]]+A*p1+B*(n-p[i]-p1));
	}
	wrn(ans);
	return 0;
}