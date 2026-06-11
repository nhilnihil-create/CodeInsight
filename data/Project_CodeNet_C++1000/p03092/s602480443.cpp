#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
#include<deque>
using namespace std;
typedef long long int LL;
typedef pair<int,int> P;
typedef pair<int,pair<int,int> > PP;
typedef pair<LL,int> LP;
const LL INF=(LL)1<<50;
const LL MAX=1e9+7;

void array_show(int *a,int n,char middle=' '){
	for(int i=0;i<n;i++)printf("%d%c",a[i],(i!=n-1?middle:'\n'));
}
void array_show(LL *a,int n,char middle=' '){
	for(int i=0;i<n;i++)printf("%lld%c",a[i],(i!=n-1?middle:'\n'));
}
LL dp[5005][5005];
int t[5005];

int main(){
	int a,b,c;
	int n;
	int i,j,k;
	int p,q;
	cin>>n;
	cin>>p>>q;
	for(i=0;i<n;i++){
		cin>>t[i];
	}
	for(i=0;i<=n;i++){
		for(j=0;j<=n;j++)dp[i][j]=INF;
	}
	dp[0][0]=0;
	for(i=0;i<=n;i++){
		for(j=0;j<n;j++){
			if(i==t[j])continue;
			if(i>t[j])dp[i][j+1]=min(dp[i][j+1],dp[i][j]+q);
			else{
				dp[i][j+1]=min(dp[i][j+1],dp[i][j]+p);
				dp[t[j]][j+1]=min(dp[t[j]][j+1],dp[i][j]);
			}
		}
	}
	LL s=INF;
	for(i=0;i<=n;i++){
		s=min(s,dp[i][n]);
	}
	cout<<s<<endl;
}
