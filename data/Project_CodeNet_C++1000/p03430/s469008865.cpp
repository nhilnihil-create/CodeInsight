#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

string S;
int K;

int dp[305][305][305];

signed main(){
    cin>>S;
    int N=S.size();
    cin>>K;

    rep(i,K+1){
        for(int len=0;len<=N;len++){
            for(int l=0;l+len<=N;l++){
                int r=l+len;
                if(len==1)dp[i][l][r]=1;
                chmax(dp[i+1][l][r],dp[i][l][r]);
                if(l)chmax(dp[i][l-1][r],dp[i][l][r]);
                if(r!=N)chmax(dp[i][l][r+1],dp[i][l][r]);
                if(l&&r!=N){
                    chmax(dp[i+(S[l-1]!=S[r])][l-1][r+1],dp[i][l][r]+2);
                }
            }
        }
    }

    cout<<dp[K][0][N]<<endl;
    return 0;
}
