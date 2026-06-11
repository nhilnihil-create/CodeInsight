#include <iostream>
#include <vector> 

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> inp(n),dp(n,0);
    
    
    for(int i=0;i<n;++i){
        cin>>inp[i];
    }
    
    dp[1] = abs(inp[1]-inp[0]);
    dp[2] = min(abs(inp[2]-inp[0]),dp[1]+abs(inp[2]-inp[1]));
    
    for(int i=3;i<n;++i){
        dp[i] = min(abs(inp[i]-inp[i-1])+dp[i-1],abs(inp[i]-inp[i-2])+dp[i-2]);
    }
    
    cout<<dp[n-1];

    return 0;
}