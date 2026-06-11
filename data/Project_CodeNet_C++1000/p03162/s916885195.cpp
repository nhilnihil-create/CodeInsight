/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector> 

using namespace std;

int main()
{
    const int INF = 1e9+7;
    int n;
    cin>>n;
    
    vector<vector<int>> inp(n,vector<int>(3)), dp(n,vector<int>(3,0));
    
    
    for(int i=0;i<n;++i){
        cin>>inp[i][0]>>inp[i][1]>>inp[i][2];
    }
    
    dp[0][0] = inp[0][0];
    dp[0][1] = inp[0][1];
    dp[0][2] = inp[0][2];
    
    for(int i=1;i<n;++i){
        dp[i][0] = inp[i][0]+max(dp[i-1][1],dp[i-1][2]);
        dp[i][1] = inp[i][1]+max(dp[i-1][0],dp[i-1][2]);
        dp[i][2] = inp[i][2]+max(dp[i-1][0],dp[i-1][1]);
    }
    
    cout<<max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));

    return 0;
}
