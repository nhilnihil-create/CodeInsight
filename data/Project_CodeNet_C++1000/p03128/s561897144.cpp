#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define mp make_pair
#define inf 1000000007
using namespace std;
int dp[10009];
signed main(){
	int n,m;
	cin>>n>>m;
	int num[10]={inf,2,5,5,4,5,6,3,7,6};
	int nm[10]={inf,inf,inf,inf,inf,inf,inf,inf,inf,inf};
	for(int i=0;i<m;i++){
		int x;
		cin>>x;
		nm[x]=num[x];
	}
	for(int i=0;i<=n;i++){
		dp[i] = -inf;
	}
	dp[0]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<10;j++){
			if(i-nm[j]>=0){
				dp[i] = max(dp[i],dp[i-nm[j]]+1);
			}
		}
	}
	int dig = dp[n];
	int cur = n;
	//for(int i=0;i<n;i++){cout<<i<<":"<<dp[i]<<endl;}
	for(int i=0;i<dig;i++){
		//cout<<i<<" "<<cur<<endl;
		int nex=0;
		for(int j=0;j<10;j++){
			if(cur >= nm[j] && ( dp[cur-nm[j]] + 1 == dp[cur] )){
				nex = max(nex,j);
			}
		}
		cout<<nex;
		cur -= nm[nex];
	}
	cout<<endl;
	return 0;
}