#include<bits/stdc++.h>
using namespace std;
int n ;
const int mxN=100,M=1e9+7;

int k,a[mxN+1];

//long long dp[mxN][mxN];
int main(){
	cin >> n >> k ;
    for(int i=0 ; i< n ;++i)cin>>a[i];

    vector<bool> dp(k+1);
    for(int i = 0 ; i< k+1 ; ++i){
        for(int j=0 ; j<n ;++j){
            if(a[j]<=i && !dp[i-a[j]]){
                dp[i]=1;
            }
        }
    }
    auto res= dp[k]?"First":"Second";
	cout << res;
}