#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
#define ch() getchar()
#define pc(x) putchar(x)
template<typename T>inline void read(T&x){
	int f;char c;
	for(f=1,c=ch();c<'0'||c>'9';c=ch())if(c=='-')f=-f;
	for(x=0;c<='9'&&c>='0';c=ch())x=x*10+(c&15);x*=f;
}
template<typename T>inline void write(T x){
	static char q[64];int cnt=0;
	if(!x)pc('0');if(x<0)pc('-'),x=-x;
	while(x)q[cnt++]=x%10+'0',x/=10;
	while(cnt--)pc(q[cnt]);
}
const int us[10]={0,2,5,5,4,5,6,3,7,6},maxn=10005;
int a[9],dp[maxn>>1][maxn];
int main(){
	int n,m;
	read(n),read(m);
	for(int i=0;i<m;++i)
		read(a[i]);
	sort(a,a+m);
	dp[0][0]=true;
	int tmp=(n+1)>>1,mx=0;
	for(int i=1;i<=tmp;++i){
		int l=min(n,i*2),r=min(n,i*7);
		for(int j=l;j<=r;++j){
			for(int k=0;k<m;++k){
				if(j>=us[a[k]]){
					dp[i][j]|=dp[i-1][j-us[a[k]]];
				}
			}
		}
		if(dp[i][n])
			mx=i;
	}
	while(mx){
		for(int i=m-1;i>=0;--i){
			if(n>=us[a[i]]&&dp[mx-1][n-us[a[i]]]){
				pc(a[i]+'0');
				--mx,n-=us[a[i]];
				break;
			}
		}
	}
	return 0;
}
