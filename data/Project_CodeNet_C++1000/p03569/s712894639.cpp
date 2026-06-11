#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string s;
  cin>>s;
  vector<char> v;
  for(auto x:s){
    if(x=='x') continue;
    v.push_back(x);
  }
  int l = v.size();
  bool can = true;
  rep(i,l){
    if(v[i]!=v[l-1-i]){
      can=false;
      break;
    }
  }
  if(!can) cout<<-1<<endl;
  else{
    int n = 0;
    map<int,int> m;
    rep(i,(int)s.size()){
      if(s[i]=='x'){
        n++;
        m[i-n]++;
      }
    }
    for(auto x:m){
      chmax(m[x.first],m[l-2-x.first]);
      chmax(m[l-2-x.first],m[x.first]);
    }
    int cnt = 0;
    for(auto x:m){
      cnt+= x.second;
    }
    for(auto x:m){
    }
    cout<<cnt-((int)s.size()-l)<<endl;
  }
}