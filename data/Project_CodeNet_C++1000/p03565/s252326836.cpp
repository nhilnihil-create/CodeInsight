#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int main(){
 string S,T; cin>>S>>T;
 string ans = "$";

 for(int i=0; i+T.size()<=S.size(); i++){
  bool ok=true;
  rep(t,T.size())
   if(S[i+t]!='?') if(S[i+t]!=T[t]) ok=false;
  if(!ok) continue;

  string tmp=S;
  rep(i,S.size()) if(tmp[i]=='?') tmp[i]='a';
  rep(t,T.size()) tmp[i+t]=T[t];
  ans = min(ans,tmp);
  if(ans=="$") ans=tmp;
 }

 if(ans=="$") cout<<"UNRESTORABLE"<<endl;
 else cout<<ans<<endl;

 return 0;
}


