#include <bits/stdc++.h> 
#include <unordered_map> 
using namespace std;  

int main() 
{ 
    int n=0,K=0;
    cin>>n>>K;
    int arr[n];
    memset(arr,0,sizeof(arr));
    for(int i=0;i<n;i++) cin>>arr[i];
    bool dp[K+1]={false};
    for(int k=0;k<=K;k++){
        bool temp=false;
        for(int i=0;i<n;i++){
            if (k>=arr[i]&&!dp[k-arr[i]]){
                temp=true;
                break;
            }
        }
        dp[k]=temp;
    }
    if (dp[K]) cout<<"First"<<endl;
    else cout<<"Second"<<endl;
    return 0;
} 