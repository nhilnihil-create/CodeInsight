#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main(){
  int n;
  cin >> n;
  string s;
  map<string, int> mapn;
  rep(i, n){
    cin >> s;
    ++mapn[s];
  }

  int m;
  cin >> m;
  string t;
  rep(i, m){
    cin >> t;
    --mapn[t];
  }

  int ans = 0;
  for (pair<string, int> count : mapn){
    if (count.second > ans) ans = count.second;
  }
  cout << ans << endl;
  return 0;
}