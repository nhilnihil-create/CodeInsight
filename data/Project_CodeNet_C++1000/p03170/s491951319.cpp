#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void solve(){

    int n,k;
    cin>>n>>k;
    
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    
    vector<int> dp(k+1 , 1);
    dp[0] = 1;
    
    for(int i=1; i<=k; i++){
        for(int j =0; j<n; j++){
            if(i-a[j] >= 0){
                int p = !(dp[i-a[j]]);
                dp[i] = min(dp[i] , p);
            }
            if(dp[i] == 0) break;
        }

    }
    
    if(dp[k] == 0){
        cout<<"First"<<endl;
    }
    else{
        cout<<"Second"<<endl;
    }
    
    return;
}

int main() {
	// your code goes here

        solve();

    return 0;
}
