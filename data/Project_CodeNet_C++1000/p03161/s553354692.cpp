#include<iostream>
#include<unordered_map>
#include<climits>
using namespace std;
unordered_map<int, int> dp;
int main(){
    int n,k;
    cin>>n>>k;
    int h[n];
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    dp[0]=0;
    dp[1]=0;
    dp[2]=abs(h[1]-h[0]);
    for(int i=3;i<n+1;i++){
        int min=INT_MAX;
        for(int j=i-1;j>-1&&j>=i-k;j--){
            if(min>(dp[j]+abs(h[i-1]-h[j-1]))){
                min=dp[j]+abs(h[i-1]-h[j-1]);
            }
        }
        dp[i]=min;
    }
    cout<<dp[n]<<endl;
    return 0;
}