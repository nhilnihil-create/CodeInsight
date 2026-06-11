#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back

const int M = 1000000007;

void add_self(int &a,int b){
	a+=b;
	if(a>=M){
		a-=M;
	}
}

int32_t main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int h,w;
    cin>>h>>w;
    vector<vector<int>>dp(h,vector<int>(w,0));
    dp[0][0]=1;
    string s[h+1];
    for(int i=0;i<h;i++){
    	cin>>s[i];
    }
    for(int i=0;i<h;i++){
    	for(int j=0;j<w;j++){
    		for(int k=i;k<=i+1;k++){
    			int col=j;
    			if(k==i){
    				col=j+1;
    			}
    			if(k<h && col<w && s[k][col]=='.'){
    				add_self(dp[k][col],dp[i][j]);
    			}
    		}
    	}
    }
    cout<<dp[h-1][w-1];
    return 0;
}