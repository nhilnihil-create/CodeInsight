#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0; i<(int)(n); i++)
using graph = vector<vector<char>>;

int main(){
  string  s;cin>>s;//cout<<s.size()<<endl;
  ll c=0,ans=0;
  rep(i,s.size()){
    if(s.at(i)=='B'){c++;}
    else{ans+=c;}
  }
  cout<<ans;
}

