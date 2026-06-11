#include <bits/stdc++.h>  
using namespace std;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
string alphabet="abcdefghijklmnopqrstuvwxyz";

int main() {
  string s,t; cin>>s>>t;
  vector<int> vs(26,0), vt(26,0);
  
  rep(i,s.size()){
    int x;
    rep(j,26){
      if(s[i]==alphabet[j]){x=j; break;}
    }
    vs[x]++;
  }
  sort(vs.begin(), vs.end());
 
  rep(i,t.size()){
    int x;
    rep(j,26){
      if(t[i]==alphabet[j]){x=j; break;}
    }
    vt[x]++;
  }
  sort(vt.begin(), vt.end());
  if(vs==vt){cout<<"Yes";}
  else{cout<<"No";}
}


