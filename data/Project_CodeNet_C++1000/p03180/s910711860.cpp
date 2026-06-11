#include<bits/stdc++.h>
using namespace std;

const int maxn=(1<<16)-1;

int n;
bool bl[maxn+5];
long long dp[maxn+5];
long long gp[maxn+5];
long long a[32][32];

int main(){
	cin>>n;
	int N=(1<<n)-1;
	//cout<<N<<'\n';
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<=N;++i){
		for(int j=0;j<n;++j){
			int tt=((1<<j)|i);
			if(tt==i||bl[tt]) continue;
			else{
				bl[tt]=1;
				gp[tt]=gp[i];
				for(int k=0;k<n;++k){
					if((i|(1<<k))==i) gp[tt]+=a[j][k];
				}
			} 
		}
	}
	for(int i=0;i<=N;++i){
		dp[i]=gp[i];
		for(int k=i;k;k=(k-1)&i){
			dp[i]=max(dp[i],dp[i^k]+dp[k]);	
		}
	}
	cout<<dp[N]<<"\n";
	return 0;
}