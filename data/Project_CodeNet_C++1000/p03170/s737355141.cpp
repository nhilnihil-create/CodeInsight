#include <iostream>
#include<vector>
#include<bits/stdc++.h> 
using namespace std;

int mod = pow(10,9) + 7;
int MAXK = 1e5 + 10; 
int MAXN = 1e3 + 10;
int N , K;
vector<int> dp(MAXK, -1);
vector<int> a(MAXN);


int solve(int k){
    if(dp[k] != -1) return dp[k];

    if(k == 0) return dp[k]=0;
    int ans = 0;
    for(int i = 0 ; i < N; i++){
        if(a[i] > k) continue;
        if(solve(k-a[i]) == 0){
            ans = 1;
            break;
        }
    }
    return dp[k] = ans;
}

int main() {
    
    cin >> N >> K;
    
    for(int i = 0 ; i < N ; i++){
        cin >> a[i];
    }

    
    if(solve(K) ) cout << "First";
    else cout << "Second";

    return 0;
}