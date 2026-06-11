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
  ll N,i,j,ans=1;string S,T;cin>>S>>T;
  vector<char>X(26,'#'),Y(26,'#');
  REP(i,S.size()){
    if(X.at(S.at(i)-'a')=='#')X.at(S.at(i)-'a')=T.at(i);
    else if(X.at(S.at(i)-'a')!=T.at(i))ans=0;
    if(Y.at(T.at(i)-'a')=='#')Y.at(T.at(i)-'a')=S.at(i);
    else if(Y.at(T.at(i)-'a')!=S.at(i))ans=0;
  }
  if(ans)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return 0;
}