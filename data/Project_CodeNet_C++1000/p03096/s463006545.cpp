#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
void read(int &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void write(ll x){
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
int n,c[200004];
ll ans=1,dp[200004];
int main(){
	read(n);
	for (int i=1;i<=n;i++){
		read(c[i]);
		if (c[i]==c[i-1]) continue;
		ans=(ans+dp[c[i]])%MOD;
		dp[c[i]]=ans;
	}
	write(ans);
}