#include <bits/stdc++.h>
using namespace std;

template<class T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<class T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}

int main(){
  int n, m; cin >> n >> m;
  vector<pair<int, int>> d(m);
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    d[i] = make_pair(a, b);
  }
  sort(d.begin(), d.end());
  int l = 0, r = 0;
  int ans = 0;
  for(int i = 0; i < m; i++){
    if(chmax(l, d[i].first)){
      if(l < r) chmin(r, d[i].second);
      else{
        chmax(r, d[i].second);
        ans++;
      }
    } 
  }
  cout << ans << endl;
}