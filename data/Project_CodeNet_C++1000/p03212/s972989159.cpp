#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FOR(i,l,r) for(i=l;i<r;i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(x) x.begin(),x.end()
#define P pair<ll,ll>
#define F first
#define S second
string NEXT(string S){
  if(S=="7")return "33";
  int N=S.size();
  if(S.at(N-1)=='7')return NEXT(S.substr(0,N-1))+"3";
  S.at(N-1)+=2;
  return S;
}
bool OK(string S){
  int i;bool x=0,y=0,z=0;
  REP(i,S.size()){
    if(S.at(i)=='3')x=1;
    if(S.at(i)=='5')y=1;
    if(S.at(i)=='7')z=1;
  }
  return x&&y&&z;
}
signed main(){
  int N,ans=0;cin>>N;string S="357";
  while(S.size()<10&&stoi(S)<=N){
    ans++;S=NEXT(S);
    while(!OK(S))S=NEXT(S);
  }
  cout<<ans<<endl;
  return 0;
}