#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int INF=1e9;

int dp[40010][202];

int main(){
    int n;
    cin>>n;
    int t[n],v[n];
    for(int i=0;i<n;i++){
        cin>>t[i];
    }
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int lmt[40010]={},crt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<2*t[i];j++){
            lmt[++crt]=2*v[i];
        }
    }
    for(int i=0;i<40010;i++){
        for(int j=0;j<202;j++){
            dp[i][j]=-INF;
        }
    }
    dp[0][0]=0;
    for(int i=1;i<40010;i++){
        for(int j=0;j<=lmt[i];j++){
            if(j>0)dp[i][j]=max(dp[i][j],dp[i-1][j-1]+2*j+1);
            if(j<lmt[i])dp[i][j]=max(dp[i][j],dp[i-1][j+1]+2*j-1);
            dp[i][j]=max(dp[i][j],dp[i-1][j]+2*j);
        }
    }
    cout<<fixed<<setprecision(5)<<dp[40009][0]/8.0<<endl;
}
