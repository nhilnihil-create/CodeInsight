#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7; 
void read(int &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void reads(string &s){
	char ch=getchar();s="";
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';s+=ch,ch=getchar());
}
void write(int x){
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
string s;
int n,dp[3003][3003],ans;
int main(){
	read(n),reads(s);
	dp[1][1]=1;
	for (int i=2;i<=n;i++){
		if (s[i-2]=='<'){
			for (int j=2;j<=i;j++)
				dp[i][j]=(dp[i][j-1]+dp[i-1][j-1])%MOD;
		}else{
			for (int j=i-1;j>=1;j--)
				dp[i][j]=(dp[i][j+1]+dp[i-1][j])%MOD; 
		}
	}
	for (int i=1;i<=n;i++) ans=(ans+dp[n][i])%MOD;
	write(ans);
}