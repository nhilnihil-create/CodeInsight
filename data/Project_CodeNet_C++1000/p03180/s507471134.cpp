#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void read(int &x){
	char ch=getchar();x=0;
	int res=1;
	for (;ch==' '||ch=='\n';ch=getchar());
	if (ch=='-') res=-1,ch=getchar();
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
	x*=res;
}
void write(ll x){
	if (x<0){
		putchar('-'),write(-x);
		return;
	}
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
int n,a[18][18];
ll num[65540];
ll dp[65540];
int main(){
	read(n);
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			read(a[i][j]);
	for (int i=1;i<(1<<n);i++)
		for (int j=0;j<n;j++) if ((1<<j)&i)
			for (int k=j+1;k<n;k++) if ((1<<k)&i)
				num[i]+=a[j][k];
	for (int i=1;i<(1<<n);i++){
		dp[i]=num[i];
		for (int j=i&(i-1);j;j=(j-1)&i){
			dp[i]=max(dp[i],dp[i^j]+num[j]);
		}
	}
	write(dp[(1<<n)-1]);
}