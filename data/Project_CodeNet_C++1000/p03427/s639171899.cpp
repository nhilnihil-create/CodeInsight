#include<bits/stdc++.h>
using namespace std;

#define lli long long int
int ar[1001];
lli dp[18][170][2];

lli getSum(int n,lli sum,int ind,bool flag){
	if(ind > n)return sum;
	lli res=0;
	int lim = 9;
	if(!flag)lim = ar[ind];
	if(dp[ind][sum][flag]!=-1)return dp[ind][sum][flag];
	for(int i=0; i<=lim; i++){
		if(flag||i<lim)
		res = max(res,getSum(n,sum+i,ind+1,true));
		else
		res = max(res,getSum(n,sum+i,ind+1,flag));
	}
	dp[ind][sum][flag]=res;
	return res;
} 

int main(){
	string n;
	cin>>n;
	int sum = 0;
	memset(dp,-1,sizeof dp);
	for(int i=0;i<n.length();i++){
		ar[i+1] = n[i] -'0';
	}
	lli one=getSum(n.size(),0,1,0);
	cout<<one;
}