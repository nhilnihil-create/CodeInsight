#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define int long long
#define _GLIBCXX_DEBUG
const int INF=1e15;

signed main(){
    int N;
    string S;
  	cin>>N>>S;
    vector<int>ls(N,0);
    vector<int>rs(N,0);
    REP(i,N){
        if(i==0){
            if(S[0]=='W') ls[0]=1;
            else ls[0]=0;
            continue;
        }
        if(S[i]=='W')ls[i]=ls[i-1]+1;
        else ls[i]=ls[i-1];
    }
    REP(i,N){
        if(i==0){
            if(S[N-1]=='E') rs[N-1]=1;
            else rs[N-1]=0;
            continue;
        }
        if(S[N-i-1]=='E')rs[N-1-i]=rs[N-i]+1;
        else rs[N-i-1]=rs[N-i];
    }
    int ans;
    REP(i,N){
        if(i==0){
            ans=rs[1];
            continue;
        }
        if(i==N-1){
            ans=min(ls[N-2],ans);
            continue;
        }
        ans=min(ans,ls[i-1]+rs[i+1]);
    }
    cout<<ans<<endl;
}
