#include<bits/stdc++.h>
using namespace std;

vector<int> a;
int dp[100010];


int moves(int index,int n,int k){
    if(index >= n-1 )
    {
        return 0;
    }
    
    if(dp[index]!=-1){
        return dp[index];
    }

    for(int i = 1;i<=k;i++){
        int a1 = 1e9;
        if(index + i < n){
            a1 = abs(a[index] - a[index+i]) + moves(index + i,n,k);
        }   
        if(dp[index]!=-1){
            dp[index] = min(dp[index],a1);
        }
        else{
            dp[index] = a1;
        }
    }

    return dp[index];

    // int a1 = 1e9;
    // int b = 1e9;
    // if(index+1 < n){
    //     a1 = abs(a[index]-a[index+1]) + moves(index + 1,n);
    // }
    // if(index + 2 < n ){
    //     b = abs(a[index]-a[index + 2]) + moves(index + 2,n);
    // }
    // return dp[index] = min(a1,b);

}

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int k;
    cin>>k;
    a.resize(n);
    memset(dp,-1,sizeof dp);

    for(int i = 0;i<n;i++){
        cin>>a[i];
    }

    cout<<moves(0,n,k)<<endl;

    return 0;
}