#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define int long long
const int MOD=1e9+7;
const int INF=1e15;

signed main(){
    int N,K;cin>>N>>K;
    int V[N];
    REP(i,N)cin>>V[i];
    int ans=0;
    priority_queue<int> que;
    for(int A=0;A<=min(N,K);A++){
        for(int B=0;B<=min(N,K)-A;B++){
            int preans=0;
            while(!que.empty())que.pop();
            REP(i,A)que.push(-V[i]);
            REP(i,B)que.push(-V[N-1-i]);
            REP(i,K-A-B){
                if(que.empty()) break;
              	int d=que.top();
                if(d>0)que.pop();
            }
            while(!que.empty()){
                preans-=que.top();
                que.pop();
            }
            ans=max(ans,preans);
        }
    }
    cout<<ans<<endl;
}