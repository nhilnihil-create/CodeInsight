#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
#include<map>
#define Set(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N=2e3+10;
const int mod=1e9+7;
template <typename T> inline void init(T&x){
	x=0;char ch=getchar();bool t=0;
	for(;ch>'9'||ch<'0';ch=getchar()) if(ch=='-') t=1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch-48);
	if(t) x=-x;return;
}
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
template <typename T>inline void upd(T&x,int y){x+=y;if(x>=mod) x-=mod;return;}
template <typename T>inline void dec(T&x,int y){x-=y;if(x <  0) x+=mod;return;}
template <typename T,typename S>inline T fpow(T x,S k){T ret=1;for(;k;k>>=1,x=1ll*x*x%mod) if(k&1) ret=1ll*ret*x%mod;return ret;}
int k;
inline int calc(int x){
	if(x==1) return 1;
	int d=x/k*k+x%k-1;
	return d;
}
int st[N][N];
int main()
{
	int n;init(n);
	if(n==1) puts("Yes\n2\n1 1\n1 1");
	else{
		k=1;
		for(;k<=1e5;++k){if(1ll*k*(k-1)/2>n) return puts("No"),0;else if(k*(k-1)/2==n) break;}
		puts("Yes");printf("%d\n",k);
		int l=1;
		for(int i=1;i<=k;++i){
			for(int j=i;j<=k;++j) {
				if(i==j) continue;
				st[i][++st[i][0]]=l;
				st[j][++st[j][0]]=l;
				++l;
			}
		}
		for(int i=1;i<=k;++i) {
			printf("%d ",k-1);
			for(int j=1;j<k;++j) printf("%d ",st[i][j]);
			puts("");
		}
	}
	return 0;
}
