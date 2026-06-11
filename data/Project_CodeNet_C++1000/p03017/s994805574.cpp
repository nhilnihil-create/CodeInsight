#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
using pii = pair<int, int>;

int main() {
  int n,a,b,c,d; cin>>n>>a>>b>>c>>d;
  string s; cin>>s;
  string s_=s.substr(a-1,max(c,d)-a);
  
  bool bo=true,t=false;
  rep(i,s_.size()-1){
    if(c<=i&&i<=b){continue;}
    if(s_[i]==s_[i+1] && s_[i]=='#'){bo=false; break;}
  }
  
  if(d<c){
    string s__=s.substr(b-2,d-b+3);

    rep(i,s__.size()-2){
      if(s__[i]==s__[i+1] && s__[i]==s__[i+2] && s__[i]=='.'){t=true; break;}
    }
  }
  
  if(!bo){cout<<"No";}
  else if(c>d && !t){cout<<"No";}
  else{cout<<"Yes";}
}
      