#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define vll vector<long long>
#define ll long long
#define pii pair<int,int>
const int mod=1e9+7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("inputf.txt","r",stdin);
    freopen("outputf.txt","w",stdout);
#endif
    
    int h,w;
    cin>>h>>w;
    char a[h][w];
    ll dp[h][w];
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>a[i][j];
            dp[i][j]=0;
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(i==0 && j==0) dp[i][j]=1;
            else if(i==0){
                if(a[i][j]=='#') dp[i][j]=0;
                else dp[i][j]=dp[i][j-1];
            }
            else if(j==0){
                if(a[i][j]=='#') dp[i][j]=0;
                else dp[i][j]=dp[i-1][j];
            }
            else{
                if(a[i][j]=='#') dp[i][j]=0;
                else dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
            }
            //cout<<dp[i][j]<<" ";
        }
        //cout<<"\n";
    }
    cout<<dp[h-1][w-1]<<"\n";
    return 0;
}