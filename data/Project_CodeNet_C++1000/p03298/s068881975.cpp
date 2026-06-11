#include <bits/stdc++.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define for1(a,b,i) for(int i=a;i<=b;++i)
#define FOR2(a,b,i) for(int i=a;i>=b;--i)
using namespace std;
typedef long long ll;
inline int read() {
	int f=1,sum=0;
	char x=getchar();
	for(;(x<'0'||x>'9');x=getchar()) if(x=='-') f=-1;
	for(;x>='0'&&x<='9';x=getchar()) sum=sum*10+x-'0';
	return f*sum;
}

#define M 50
int n;
ll f[M][M];
char s[M],a[M],b[M];

int main() {
	//freopen("a.in","r",stdin);
	n=read();
	scanf("%s",s+1);
	ll ans=0;
	FOR2((1<<n)-1,0,i) {
		int cnt=0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for1(1,n,j) 
			if(i>>j-1&1) a[++cnt]=s[j];
			else b[j-cnt]=s[j];
		memset(f,0,sizeof(f));
		f[0][0]=1;
		for1(0,n-1,j) for1(0,cnt,k) {
			if(!f[j][k]) continue;
			if(k!=cnt&&s[2*n-j]==a[k+1]) f[j+1][k+1]+=f[j][k];
			if(s[2*n-j]==b[j+1-k]) f[j+1][k]+=f[j][k]; 
		}
		ans+=f[n][cnt];
	}
	cout<<ans<<endl;
}