/*
 *  author: chw0501
 *  reference: 
 *  created: 25.04.2020 01:44:29(UTC)
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define MOD 1000000007 
#define INF 987654321 

int n;
ll arr[16][16];
ll sum[1<<16];
ll dp[1<<16];

//dp[s]: s집합이 남아있을 때 앞으로 얻을 수 있는 최대점수
ll solve(int s){
	ll& ret=dp[s];
	if(ret!=-1ll) return ret;
	if(s==0) return ret=0;
	ret=0;
	for(int i=s;i>0;i=(i-1)&s){
		ret=max(ret,sum[i]+solve(s-i));
	}
	return ret;
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%lld",&arr[i][j]);
		}
	}
	for(int i=1;i<(1<<n);i++){
		vector<int> v;
		for(int j=0;j<n;j++){
			if(((1<<j)&i) !=0){
				v.push_back(j);
			}
		}
		for(int x:v){
			for(int y:v){
				sum[i]+=arr[x][y];
			}
		}
		sum[i]/=2ll;
	}
	memset(dp,-1ll,sizeof(dp));
	cout<<solve((1<<n)-1);
	return 0;
}