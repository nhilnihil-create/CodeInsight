#include<bits/stdc++.h>
#define ll long long
#define INF 1e18
#define N 5010
using namespace std;
template <typename T> void read(T &x){
	x=0;char c=getchar();int fh=1;
	while (!isdigit(c)){if (c=='-')fh=-1;c=getchar();}
	while (isdigit(c))x=x*10+c-'0',c=getchar();
	x*=fh;
}
ll n,yo,zu,mi[N],a[N],dp[N][N];
int main(){
	read(n);read(yo);read(zu);mi[0]=INF;
	for (int i=1;i<=n;i++) read(a[i]);
	for (int i=1;i<=n+1;i++){
		for (int j=1;j<=n;j++) mi[j]=min(mi[j-1],dp[i-1][j]);
		for (int j=1;j<=n;j++){
			dp[i][j]=mi[j];
			if (j<a[i])dp[i][j]+=yo;
			if (j>a[i])dp[i][j]+=zu;
		}
	}
	cout<<mi[n]<<endl;
	return 0;
}