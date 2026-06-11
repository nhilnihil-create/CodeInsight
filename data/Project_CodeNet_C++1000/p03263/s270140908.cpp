#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,0,n+1)
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
const int MOD=1e9+7;
const int INF=1e18;

signed main(){
    int H,W;cin>>H>>W;
    int A[H][W];
    REP(i,H)REP(j,W)cin>>A[i][j];
    int X[H*W];
    int Y[H*W];
    for(int i=0;i<H*W;i++){
        X[i]=i/W;
        if(i/W%2==0) Y[i]=i%W;
        else Y[i]=W-1-i%W;
    }
    int N=0;
    vector<pair<pair<int,int>,pair<int,int>>>ans(H*W);
    REP(i,H*W-1){
        if(A[X[i]][Y[i]]%2==1){
            A[X[i]][Y[i]]--;
            A[X[i+1]][Y[i+1]]++;
            pair<pair<int,int>,pair<int,int>> p=mp(mp(X[i],Y[i]),mp(X[i+1],Y[i+1]));
            ans[N]=p;
            N++;
        }
    }
    ans.resize(N);
    cout<<N<<endl;
    REP(i,N){
        cout<<ans[i].first.first+1<<" "<<ans[i].first.second+1<<" "<<ans[i].second.first+1<<" "<<ans[i].second.second+1<<endl;
    }
}
