#include <iostream>
#include <cstring>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;
typedef long long int ll;
ll dp[100001];

ll frog(vector<int> height,int n,int k){
	for(int i=0;i<k;i++){
		dp[i]=abs(height[i]-height[0]);
	}
	for(int i=k;i<n;i++){
		dp[i]=INT_MAX;
		for(int j=i-k;j<i;j++){
			dp[i]=min(dp[i],dp[j]+abs(height[j]-height[i]));
		}
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
    int k;cin>>k;
    vector<int> height;
    for(int i=0;i<n;i++){
    	int p;cin>>p;
    	height.push_back(p);
    }
    ll res=frog(height,n,k);
    cout<<res<<endl;

}