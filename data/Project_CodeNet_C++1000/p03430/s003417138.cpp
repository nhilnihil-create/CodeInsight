#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=305,INF=1<<30;
int dp[MAX][MAX][MAX];

int main(){
    
    string S;cin>>S;
    int N=S.size();
    int K;cin>>K;
    int maxi=0;
    
    for(int i=0;i<N;i++){
        dp[i][i][0]=1;
    }
    
    for(int w=1;w<N;w++){
        for(int l=0;l<N;l++){
            int r=l+w;
            if(r>=N) continue;
            for(int k=0;k<=K;k++){
                if(k==0){
                    if(S[l]==S[r]){
                        dp[l][r][k]=max(dp[l][r][k],dp[l+1][r-1][k]+2);
                    }else{
                        dp[l][r][k]=max({dp[l][r][k],dp[l+1][r][k],dp[l][r-1][k],dp[l+1][r-1][k]});
                    }
                }else{
                    if(S[l]==S[r]){
                        dp[l][r][k]=max(dp[l][r][k],dp[l+1][r-1][k]+2);
                    }else{
                        dp[l][r][k]=max({dp[l][r][k],dp[l+1][r][k],dp[l][r-1][k],dp[l+1][r-1][k]});
                        dp[l][r][k]=max({dp[l][r][k],dp[l+1][r-1][k-1]+2});
                    }
                }
            }
        }
    }
    
    for(int k=0;k<=K;k++){
        maxi=max(maxi,dp[0][N-1][k]);
    }
    
    cout<<maxi<<endl;
}




