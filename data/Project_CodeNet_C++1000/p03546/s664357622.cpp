#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(int)(s);i<(int)(n);i++)

const int INF = 1e+9+7;
const int N=10;
int main(){
    int H,W;
    cin >> H >> W;
    vector<vector<int>> dp(N,vector<int>(N));

    rep(i,N){
        rep(j,N){
            cin >> dp[i][j];
        }
    }

    

    rep(k,N){
        rep(i,N){
            rep(j,N){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }

    int ans=0;
    int tmp;
    rep(i,H){
        rep(j,W){
            cin >> tmp;
            if(tmp!=-1){
                ans+=dp[tmp][1];
            }

        }
    }

    cout << ans << endl;
}