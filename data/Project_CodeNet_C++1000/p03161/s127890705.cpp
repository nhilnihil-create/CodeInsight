#include <bits/stdc++.h>
#define pb push_back
#define Int long long
using namespace std;

const int MAXN=500005;
const long MOD=(long)(1e9+7);
vector<int> adj[MAXN];
vector<pair<int,int>> G[MAXN];

Int N,M,K;
Int B,C,H,W;
Int X,Y,Z;
vector<Int> A;

Int ceilS(Int x,Int y){
    return (x+y-1)/y;
}
using D=long double;

Int perform(Int x){
    return (x*(x+1))/2LL;
}

int main()
{
        cin>>N>>K;
        A.resize(N);
        
        for(auto &x:A) cin>>x;
        
        vector<Int> dp(N,1e9);
        
        dp[0]=0; dp[1]=abs(A[1]-A[0]);
        for(int i=2;i<N;++i){
            for(int j=1;j<K+1;++j){
                if(i-j>=0){
                    dp[i]=min(dp[i],dp[i-j]+abs(A[i]-A[i-j]));
                }
            }
        }
        cout<<dp[N-1]<<"\n";
}
