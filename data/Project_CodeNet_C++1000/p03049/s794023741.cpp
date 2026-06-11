#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define int long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
const int MOD=1e9+7;
const int INF=1e15;

signed main(){
    int N;cin>>N;
    string A[N];
    int ans=0;
    int tb=0;
    int ba=0;
    int tbba=0;
    REP(i,N){
        cin>>A[i];
        if(A[i][0]=='B')tb++;
        if(A[i][A[i].size()-1]=='A')ba++;
        if((A[i][0]=='B')&&(A[i][A[i].size()-1]=='A'))tbba++;
        REP(j,A[i].size()-1){
            if(A[i][j]=='A'&&A[i][j+1]=='B')ans++;
        }
    }
    int d=0;
  	tb-=tbba;
  	ba-=tbba;
  	if(tbba==0){
      d=min(tb,ba);
    }
  	else{
      if(tb+ba==0) d=tbba-1;
      else d=tbba+min(tb,ba);
    }
    cout<<ans+d<<endl;
}