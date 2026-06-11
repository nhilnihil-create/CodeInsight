#include <iostream>
#include<cstring>
using namespace std;
int ways(int n,int k,int stones[]){
    bool dp[k+1];
    memset(dp,false,sizeof dp);
    dp[0]=false;
    for(int i=0;i<=k;i++){
        for(int j=0;j<n;j++){
            if(stones[j]<=i&&dp[i-stones[j]]==false){
                dp[i]=true;
                
            }
        }
    }
    return dp[k];
}
int main() {
    int n,k;
    cin>>n>>k;
   int stones[n];
    for(int i=0;i<n;i++){
        cin>>stones[i];
    }
    bool ans=ways(n,k,stones);
    if(ans){
        cout<<"First";
    }
else
cout<<"Second";
}
