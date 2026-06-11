#include<bits/stdc++.h>
using namespace std;

vector<int> a;
int dp[100010];


int moves(int index,int n){
    if(index >= n-1 )
    {
        return 0;
    }
    
    if(dp[index]!=-1){
        return dp[index];
    }

    int a1 = 1e9;
    int b = 1e9;
    if(index+1 < n){
        a1 = abs(a[index]-a[index+1]) + moves(index + 1,n);
    }
    if(index + 2 < n ){
        b = abs(a[index]-a[index + 2]) + moves(index + 2,n);
    }
    return dp[index] = min(a1,b);

}

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    a.resize(n);
    memset(dp,-1,sizeof dp);

    for(int i = 0;i<n;i++){
        cin>>a[i];
    }

    cout<<moves(0,n)<<endl;

    return 0;
}