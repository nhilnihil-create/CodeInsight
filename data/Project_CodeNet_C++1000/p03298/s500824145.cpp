#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
char str[45];
ll dp[45][45];
string a,b;
int main(){
	int n;
	scanf("%d",&n);
	scanf("%s",str+1);
	reverse(str+n+1,str+n+n+1);
	int limt=1<<n;
	ll ans=0;
	for(int s=0;s<limt;s++){
		a=b="";
		memset(dp,0,sizeof dp);
		for(int i=0;i<n;i++){
			if((1<<i)&s) a+=str[i+1];
			else b+=str[i+1];
		}
		dp[0][0]=1;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=(int)a.size();j++){
				if(j+1<=(int)a.size() && str[n+i]==a[j])
					dp[i][j+1]+=dp[i-1][j];
				if(i-j<=(int)b.size() && str[n+i]==b[i-j-1])
					dp[i][j]+=dp[i-1][j];
			}
		}
		ans+=dp[n][a.size()];
	}
	printf("%lld\n",ans);
	return 0;
}