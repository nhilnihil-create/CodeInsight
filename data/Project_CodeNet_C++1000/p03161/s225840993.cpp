
#include <iostream>
#include <vector> 

using namespace std;

int main()
{
    const int INF = 1e9+7;
    int n,k;
    cin>>n>>k;
    
    vector<int> inp(n),dp(n,0);
    
    
    for(int i=0;i<n;++i){
        cin>>inp[i];
    }
    
    for(int i=1;i<n;++i){
        
        int count = 0,mini = INF;
        for(int j=i-1;j>=0&&((count++)<k);j--)
        {
            mini = min(mini , abs(inp[i]-inp[j])+dp[j]); 
        }
        dp[i] = mini;
    }
    
    cout<<dp[n-1];

    return 0;
}