//writer：Sakura
//problem：Reversed LCS
//id：021_d
//from：Actor

#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string s;
ll n;
int dp[305][305][305];

int dfs(int l,int r,int sum){
	if(dp[l][r][sum]!=-1)return dp[l][r][sum];
	if(l>r)return 0;
	if(l==r)return 1;
	int ans=0;
	if(sum>0){
		ans=max(ans,dfs(l+1,r-1,sum-1)+2);
	}
	ans=max(ans,dfs(l+1,r,sum));
	ans=max(ans,dfs(l,r-1,sum));
	if(s[l]==s[r])ans=max(ans,dfs(l+1,r-1,sum)+2);
	return dp[l][r][sum]=ans;
}

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>s;
	scanf("%lld",&n);
	memset(dp,-1,sizeof(dp));
	int _=dfs(0,s.size()-1,n);
	printf("%lld\n",_);
	return 0;
}
