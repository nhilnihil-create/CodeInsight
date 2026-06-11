#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin>>N;
    vector<int>A;
    for(int i=0;i<N;i++){
        int x;
        cin>>x;
        A.push_back(x);
    }
    int dp[N+2];
    dp[1]=0;
    if(N==1){
        cout<<0<<endl;
        return 0;
    }
    dp[2]=abs(A[1]-A[0]);
        if(N==2){
    cout<<dp[2]<<endl;
    return 0;
    }
    dp[3]=min(abs(A[2]-A[0]),dp[2]+abs(A[2]-A[1]));
        if(N==3){
    cout<<dp[3]<<endl;
    return 0;
    }
    for(int i=4;i<=N;i++){
        dp[i]=min(dp[i-1]+abs(A[i-1]-A[i-2]),dp[i-2]+abs(A[i-1]-A[i-3]));
    }
    cout<<dp[N]<<endl;
    return 0;
}