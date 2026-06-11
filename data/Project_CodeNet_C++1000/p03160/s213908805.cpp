#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll dp[100001];

ll frog(vector<int> height,int n){
	dp[0]=0;
	dp[1]=abs(height[1]-height[0]);
	for(int i=2;i<n;i++){
		dp[i]=min(dp[i-2]+abs(height[i-2]-height[i]),dp[i-1]+abs(height[i-1]-height[i]));
	}
	return dp[n-1];
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
    freopen("output.txt","w", stdout);
#endif


    memset(dp,0,sizeof(dp));
    int n;cin>>n;
    vector<int> height;
    for(int i=0;i<n;i++){
    	int p;cin>>p;
    	height.push_back(p);
    }
    ll res=frog(height,n);
    cout<<res<<endl;

}