#include <bits/stdc++.h>
using namespace std;
string arr;
long long getsum(int ind,int sum,int flag,vector<vector<vector<long long> > >&dp){
	if(ind==arr.size()) return sum;
	if(dp[ind][sum][flag]!=-1) return dp[ind][sum][flag];
	int limit=9;
	if(!flag) limit=arr[ind]-'0';
	long long res=0;
	for(int i=0;i<=limit;i++){
		if(flag||i<limit){
			res=max(res,getsum(ind+1,sum+i,1,dp));
		}
		else res=max(res,getsum(ind+1,sum+i,0,dp));
	}
	dp[ind][sum][flag]=res;
	return res;
	
	
}
int main() {
	
		long long a;
		cin>>a;
	
	
		arr=to_string(a);
		
		
			vector<vector<vector<long long> > >dp(arr.size()+1,vector<vector<long long> >(200,vector<long long>(2,-1)));
		long long u=getsum(0,0,0,dp);
		
		
		cout<<u<<endl;
		
		
	
	
	return 0;
}