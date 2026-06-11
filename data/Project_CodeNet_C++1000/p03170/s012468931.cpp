#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> dp(k+1,false);
    for(int i=0;i<=k;i++){
        for(int x:arr){
            if(i>=x && !dp[i-x]){
                dp[i]=true;
            }
        }
    }
    if(dp[k])
    cout<<"First"<<endl;
    else 
    cout<<"Second"<<endl;
    return 0;
}