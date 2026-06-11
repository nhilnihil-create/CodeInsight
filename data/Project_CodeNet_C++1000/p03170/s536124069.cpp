#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,k;
    cin>>n>>k;

    vector<bool>dp(k+1,false);

    vector<int>v(n);
    for(int &x:v)cin>>x,dp[x] = true;

    for(int i=1;i<=k;i++){
        for(int j=0;j<n;j++){
            if(i>=v[j])
            if(!dp[i-v[j]])dp[i] = true;
        }
    }

    if(dp[k])cout<<"First";
    else cout<<"Second";


    return 0;

}