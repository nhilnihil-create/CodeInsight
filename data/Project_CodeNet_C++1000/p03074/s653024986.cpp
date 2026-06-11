#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
const int MOD=1e9+7;
const int INF=1e18;

signed main(){
    int N,K;string S;cin>>N>>K>>S;
    vector<int>D;
  	if(S[0]!='1')D.eb(0);
    int ren=0;
    REP(i,N-1){
        if(S[i]!=S[i+1]){
            D.eb(ren+1);
            ren=0;
        }
        else ren++;
    }
    D.eb(ren+1);
  	if(S[S.size()-1]!='1')D.eb(0);
    int ans=0;
	vector<int>SUM(D.size()+1,0);
  	REP(i,D.size())SUM[i+1]=SUM[i]+D[i];
    int left=0;int right=K*2+1;
  	for(;left<SUM.size();left+=2){
      	if(right>=SUM.size())right=SUM.size()-1;
      	ans=max(ans,SUM[right]-SUM[left]);
      	right+=2;
    }
    cout<<ans<<endl;
}
