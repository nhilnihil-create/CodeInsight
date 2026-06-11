#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<fstream>
using namespace std;
string s;
int dp[(1<<26)+1];
long long now=0;
int main(){
	cin>>s;
	memset(dp,63,sizeof(dp));
	dp[0]=0;
	for(int i=0;i<=s.length()-1;i++){
		now^=(1<<(s[i]-'a'));
		for(int j=0;j<=25;j++){
			if((now^(1<<j))!=now){
				dp[now]=min(dp[now],dp[now^(1<<j)]+1);
			}
		}
	}
	cout<<max(1,dp[now])<<endl;
	return 0;
}
/*

in:
abcabcxabcx

out:
3

*/