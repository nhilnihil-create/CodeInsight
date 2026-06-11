#include <bits/stdc++.h>
using namespace std;
const int Match[10]={0,2,5,5,4,5,6,3,7,6};
int n,m,a[9],dp[20000];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)dp[i]=-1e9;
    for(int i=0;i<m;i++)cin>>a[i];
    for(int i=0;i<=n;i++){
        for(int j=0;j<m;j++){
            int x=Match[a[j]];
            dp[i+x]=max(dp[i+x],dp[i]+1);
        }
    }
    sort(a,a+m,greater<int>());
    int x=dp[n];
    for(int i=0;i<x;i++){
        for(int j=0;j<m;j++){
            if(n-Match[a[j]]>=0&&dp[n-Match[a[j]]]+1==dp[n]){
                n-=Match[a[j]];
                cout<<a[j];
                break;
            }
        }
    }
    cout<<endl;
}