#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define int long long
const int MOD=1e9+7;
const int INF=1e15;

signed main(){
    priority_queue<int>que;
    REP(i,3){
        int a;cin>>a;
        que.push(a);
    }
    int K;cin>>K;
    REP(i,K){
        int d=que.top();
        d*=2;
        que.pop();
        que.push(d);
    }
    int ans=0;
    REP(i,3){
        ans+=que.top();
        que.pop();
    }
    cout<<ans<<endl;
}