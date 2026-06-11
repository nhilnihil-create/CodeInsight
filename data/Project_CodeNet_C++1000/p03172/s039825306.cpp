#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
void addself(int &a,int b){
	a+=b;
	if(a>=mod){
		a-=mod;
	}
}
void subself(int &a,int b){
	a-=b;
	if(a<0){
		a+=mod;
	}
}
int main(){
	int n,k;
	cin>>n>>k;
	int dp[k+1]={0};
	dp[0]=1;
	int upto;
	for(int i=0;i<n;i++){
		cin>>upto;
		int diff[k+1]={0};
		for(int used=k;used>=0;used--){
			int l=used+1;
			int r=used+min(upto,k-used);
			int tmp=dp[used];
			if(l<=r){
				addself(diff[l],tmp);
				if(r+1<=k){
					subself(diff[r+1],tmp);
				}
			}
		}
		int prefix_sum=0;
		for(int j=0;j<=k;j++){
			addself(prefix_sum,diff[j]);
			addself(dp[j],prefix_sum);
		}
	}
	cout<<dp[k]<<endl;
}