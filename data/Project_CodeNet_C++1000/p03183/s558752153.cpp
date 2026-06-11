#include<iostream>
#include<vector>
#include<algorithm>
#define int long long
using namespace std;
const int N=1e3+2;
const int M=2e4+2;
pair<pair<int,int>,int>  lis[N];
int dp[M];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,i,j,k,l;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>lis[i].first.first>>lis[i].first.second>>lis[i].second;
	}
	sort(lis+1,lis+1+n,[&](pair<pair<int,int>,int> x,pair<pair<int,int>,int> y){
		return x.first.first+x.first.second>y.first.first+y.first.second;
	}); 
	for(i=1;i<=n;i++){
		for(j=lis[i].first.first;j<=lis[i].first.second+lis[i].first.first;j++){
			dp[j-lis[i].first.first]=max(dp[j-lis[i].first.first],dp[j]+lis[i].second);
		}
//		for(j=1;j<=5;j++){
//			cout<<dp[j]<<" ";
//		}
//		cout<<endl;
	}
	cout<<dp[0];
}