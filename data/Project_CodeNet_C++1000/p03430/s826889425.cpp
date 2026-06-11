#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000

string S;

int get(int l,int r,int k){
	if(k<0)return -100000;
	if(r==l)return 1;
	if(r<l)return 0;
	static vector<vector<vector<int>>> dp(S.size()+1,vector<vector<int>>(S.size()+1,vector<int>(S.size()+1,-1)));
	if(dp[l][r][k]!=-1)return dp[l][r][k];
	int ret = 0;
	ret = max(ret,get(l+1,r,k));
	ret = max(ret,get(l,r-1,k));
	ret = max(ret,get(l+1,r-1,k-1)+2);
	if(S[l]==S[r])ret = max(ret,get(l+1,r-1,k)+2);
	dp[l][r][k]=ret;
	return ret;
}

int main(){
	
	cin>>S;
	
	int K;
	cin>>K;
	
	cout<<get(0,S.size()-1,K)<<endl;
	
	return 0;
}