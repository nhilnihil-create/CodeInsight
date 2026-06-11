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

vector<ll> d(10, 1000000);
int c[10][10];

void func(int s, int cr, vector<int>& v){
  if(cr == 1){
    ll sum = 0;
    for(int i = 1; i < v.size(); i++){
      //cout << c[v[i - 1]][v[i]] << endl;
      sum += c[v[i - 1]][v[i]];
      //cout << v[i] << " ";
    }
    d[s] = min(d[s], sum);
    //cout << " : " << sum << endl;
    return;
  }
  for(int i = 0; i < 10; i++){
    int j;
    for(j = 0; j < v.size(); j++){
      if(v[j] == i) break;
    }
    if(j < v.size()) continue;
    v.push_back(i);
    func(s, i, v);
    v.pop_back();
  }
  return;
}

void solve(){
  int h, w; cin >> h >> w;
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      cin >> c[i][j];
    }
  }

  for(int i = 0; i < 10; i++){
    vector<int> v;
    if(i == 1) continue;
    v.push_back(i);
    func(i, i, v);
  }

  ll ans = 0;
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      int x; cin >> x;
      if(x == -1 || x == 1) continue;
      ans += d[x];
    }
  }
  cout << ans << endl;

  /*for(int i = 0; i < 10; i++){
    cout << d[i] << endl;
  }*/

  return;
}

int main(){
  solve();
  return 0;
}
