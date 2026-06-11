#include <bits/stdc++.h>
#define pb push_back
#define Int long long
using namespace std;

const int MAXN=500005;
const long MOD=(long)(1e9+7);
vector<int> adj[MAXN];
vector<pair<int,int>> G[MAXN];

Int N,M,K;
//Int B,C,H,W;
Int X,Y,Z;
//vector<Int> A;

Int ceilS(Int x,Int y){
    return (x+y-1)/y;
}
using D=long double;

Int perform(Int x){
    return (x*(x+1))/2LL;
}

int main()
{
        cin>>N;
        Int A[N][3];
        
        for(int i=0;i<N;++i){
            cin>>A[i][0]>>A[i][1]>>A[i][2];
        }
        
        Int dp[N][3];
        for(int i=0;i<3;++i) dp[0][i]=A[0][i];
        
        for(int i=1;i<N;++i){
            dp[i][0]=max(dp[i-1][1],dp[i-1][2])+A[i][0];
            dp[i][1]=max(dp[i-1][0],dp[i-1][2])+A[i][1];
            dp[i][2]=max(dp[i-1][0],dp[i-1][1])+A[i][2];
        }
        Int ans=max({dp[N-1][0],dp[N-1][1],dp[N-1][2]});
        cout<<ans<<"\n";
        
}
