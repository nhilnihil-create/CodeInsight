#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
  string s,t;
  cin >> s >> t;
  int n = s.size();
  vector<vector<bool>>ss(26,vector<bool>(26,false));
  vector<vector<bool>>tt(26,vector<bool>(26,false));
  rep(i,n){
    ss[s[i]-'a'][t[i]-'a'] = true;
    tt[t[i]-'a'][s[i]-'a'] = true;
  }
  rep(i,26){
    int sc = 0,tc = 0;
    rep(j,26){
      if(ss[i][j]) sc++;
      if(tt[i][j]) tc++;
    }
    if(sc >= 2 || tc >= 2){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}