#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <cmath>
typedef long long ll;
using namespace std;

void solve(){
  ll h, w, a, b; cin >> h >> w;
  vector<vector<ll> > v(h, vector<ll>(w));
  vector<pair<pair<int, int>, pair<int, int> > > ans;
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      cin >> v[i][j];
    }
  }
  for(int i = 0; i < h; i++){
    if(i % 2 == 0){
      for(int j = 0; j < w; j++){
        if(v[i][j] % 2 == 1){
          if(j + 1 < w){
            a = i;
            b = j + 1;
          }
          else{
            if(i + 1 >= h) break;
            a = i + 1;
            b = w - 1;
          }
          v[i][j]--;
          v[a][b]++;
          ans.push_back(make_pair(make_pair(i, j), make_pair(a, b)));
        }
      }
    }
    else{
      for(int j = w - 1; j >= 0; j--){
        if(v[i][j] % 2 == 1){
          if(j - 1 >= 0){
            a = i;
            b = j - 1;
          }
          else{
            if(i + 1 >= h) break;
            a = i + 1;
            b = 0;
          }
          v[i][j]--;
          v[a][b]++;
          ans.push_back(make_pair(make_pair(i, j), make_pair(a, b)));
        }
      }
    }
  }
  cout << ans.size() << endl;
  for(int i = 0; i < ans.size(); i++){
    cout << ans[i].first.first + 1 << " " << ans[i].first.second + 1 << " " << ans[i].second.first + 1 << " " << ans[i].second.second + 1 << endl;
  }
  return;
}

int main(){
  solve();
  return 0;
}
