#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int dp[100001] ={0};

string solve(vector<int> &v, int k){
    
    for(int i=1;i<=k;i++){
        for(auto move : v){
            
            if(move>i)continue;
            
            else if(dp[i-move] == 0){
                dp[i] =1;
            }
        }
        
    }
    if(dp[k] == 0)return "Second";
    else return "First";
}


int main() {
    memset(dp, 0, sizeof dp);
    
	int n, k;
	cin>>n>>k;
	vector <int> v(n);
	for(int i=0;i<n;i++){
	    cin>>v[i];
	}
	for(int i=0;i<=k;i++)
	    dp[i] = 0;
	    
	cout<<solve(v, k)<<endl;
	return 0;
}