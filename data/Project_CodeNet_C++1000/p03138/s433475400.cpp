#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define int long long
#define mp make_pair
#define _GLIBCXX_DEBUG
const int INF=1e15;
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
const int MAX_DIGIT=50;
vector<vector<int>>dp(100,vector<int>(2,-1));

signed main(){
    int N,K;cin>>N>>K;
    int A[N];
    REP(i,N)cin>>A[i];
    dp[0][0]=0;
    REP(d,MAX_DIGIT){
        int mask=1ll<<(MAX_DIGIT-d-1);
        int num=0;
        for(int i=0;i<N;i++){
            if(A[i]&mask)num++;
        }
        int cost0=mask*num;
        int cost1=mask*(N-num);
        if(dp[d][1]!=-1){
            chmax(dp[d+1][1],dp[d][1]+max(cost0,cost1));
        }
        if(dp[d][0]!=-1){
            if(K&mask){
                chmax(dp[d+1][1],dp[d][0]+cost0);
            }
        }
        if(dp[d][0]!=-1){
            if(K&mask) chmax(dp[d+1][0],dp[d][0]+cost1);
            else chmax(dp[d+1][0],dp[d][0]+cost0);

        }
    }
    cout<<max(dp[MAX_DIGIT][0],dp[MAX_DIGIT][1])<<endl;
}