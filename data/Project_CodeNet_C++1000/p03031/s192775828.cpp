#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < n; ++i)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//~ using P = pair<int, int>;

int n, m;

bool chk(vector<int> &on, vector<vector<int>> &s, vector<int> &p){
  int c;
  for(int i=0; i<m; ++i){
    c=0;
    for(int j=0; j<10; ++j){
      if(s[i][j]==-1) break;
      if(on[s[i][j]]) c++;
    }
    if(c%2==p[i]){
      continue;
    }
    else{
      return false;
    }
  }
  return true;
}

int main(){
  int k;
  vector<vector<int>> s(11, vector<int>(11, -1)); // どのスイッチに紐付いているか
  vector<int> p(11, -1); // 点灯条件
  
  cin >> n >> m;
  rep(i, m) {
    cin >> k;
    rep(j, k){
      cin >> s[i][j];
      s[i][j]--;
    }
  }
  rep(i, m) cin >> p[i];
  
  int cnt=0;
  vector<int> on(n); // スイッチ状態
  for(int bit=0; bit < (1<<n); ++bit){
    
    for(int i=0; i<n; ++i){
      if(bit & (1<<i))
        on[i]=1;
      else
        on[i]=0;
    }

    if(chk(on, s, p)){
      cnt++;
    }
  }
  
  cout << cnt << endl;  
  return 0;
}
