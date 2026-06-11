#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FOR(i,l,r) for(i=l;i<r;i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(x) x.begin(),x.end()
#define P pair<ll,ll>
#define F first
#define S second
signed main(){
  ll N,M,i,j;cin>>N>>M;
  vector<vector<P>>X(N,vector<P>());
  vector<P>ans(M);
  REP(i,M){
    cin>>ans.at(i).F>>j;X.at(ans.at(i).F-1).push_back(P(j,i));
  }
  REP(i,N){
    sort(ALL(X.at(i)));
    REP(j,X.at(i).size())ans.at(X.at(i).at(j).S).S=j+1;
  }
  REP(i,M)printf("%06ld%06ld\n",ans.at(i).F,ans.at(i).S);
  return 0;
}