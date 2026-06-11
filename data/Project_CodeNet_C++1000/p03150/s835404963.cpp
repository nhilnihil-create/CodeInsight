#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0; i<(int)(n); i++)
using graph = vector<vector<char>>;

int main(){
  string  s;cin>>s;
  bool b=false;
  rep(i,8){
    string t=s.substr(0,i);
    string u=s.substr(s.size()+i-7,7-i);
    if(t+u=="keyence"){b=true;break;}
  }
  if(b)cout<<"YES";
  else{cout<<"NO";}
}



