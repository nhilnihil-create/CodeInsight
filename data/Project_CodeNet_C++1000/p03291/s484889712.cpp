#include <bits/stdc++.h>
using namespace std;

using ll = long long;
static const ll MOD = 1e9 + 7;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  string s;
  cin >> s;
  
  vector<vector<ll>> x(s.size() + 1, vector<ll>(4));
  x.at(s.size()).at(0) = x.at(s.size()).at(1) = x.at(s.size()).at(2) = 0;
  x.at(s.size()).at(3) = 1;
  
  for(int i = s.size() - 1; i >= 0; i--){
    if(s.at(i) == '?') x.at(i).at(3) = x.at(i + 1).at(3) * 3;
    else x.at(i).at(3) = x.at(i + 1).at(3);
    x.at(i).at(3) %= MOD;
  }
  
  for(int i = s.size() - 1; i >= 0; i--){
    for(int j = 0; j < 3; j++){
      if(s.at(i) == '?') x.at(i).at(j) = x.at(i + 1).at(j) * 3;
      else x.at(i).at(j) = x.at(i + 1).at(j);
      if(s.at(i) == '?' || s.at(i) == 65 + j) x.at(i).at(j) += x.at(i + 1).at(j + 1);
      x.at(i).at(j) %= MOD;
    }
  }
  
  cout << x.at(0).at(0) << '\n';
}