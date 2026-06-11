#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int64_t MOD=1000000007;
const long long INF = 1LL<<60;

int main() {
  string S; cin>>S;
  int T=S.size();
  if(T<26){
    rep(i,26){
      char s;
      s=(i+97);
      bool id=true;
      rep(j,T) if(s==S.at(j))id=false;
      if(id){
        S.push_back(s);
        cout<<S;
        break;
      }
    }
  }
  else{
    int i=T-2;
    for(;i>=0;i--){
      if(S.at(i)<S.at(i+1)) break;
    }
    if(i<0) cout<<-1;
    else{
      for(int k=(int)S.at(i)-96;k<26;k++){
        char s;
        s=(k+97);
        bool id=true;
        rep(l,i) if(s==S.at(l)) id=false;
        if(id){
          S.at(i)=s;
          break;
        }
      }   
      rep(z,i+1) cout<<S.at(z);
    }
  }   
}
