#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int mod=(1e9)+7;
const int maxn=3010;
int n,dp[maxn][maxn],s[maxn][maxn],tmp,ans;
char S[maxn];
void update(int &x,int y) {
	x+=y; if (x>=mod) x-=mod;
}
int main() {
//	freopen("1.txt","r",stdin);
	read(n);
	scanf("%s",S+1);
	dp[1][1]=s[1][1]=1;
	int l,r;
	for (int i=2;i<=n;i++) {
		for (int j=1;j<=i;j++) {
			if (S[i-1]=='>') {
				//k>=j
				l=j; r=i-1;
			} else {
				//k<j
				l=1; r=j-1;
			}
			dp[i][j]=(s[i-1][r]+mod-s[i-1][l-1])%mod;
			s[i][j]=(s[i][j-1]+dp[i][j])%mod;
			continue;
			for (int k=1;k<i;k++) {
				tmp=k;
				if (k>=j) tmp++;
				if (S[i-1]=='>'&&tmp<j) continue;
				if (S[i-1]=='<'&&tmp>j) continue;
				update(dp[i][j],dp[i-1][k]);
			}
		}
	}
	for (int i=1;i<=n;i++) update(ans,dp[n][i]);
	printf("%d\n",ans);
	return 0;
}