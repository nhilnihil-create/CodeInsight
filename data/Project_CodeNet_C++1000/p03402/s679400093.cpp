#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
#include <cassert>
#define rep(i,n) for(int i = 0; i < n; ++i )
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int a,b;
  cin >> a >> b;
  vector<vector<char>> ans;
  rep(i,50) ans.emplace_back(vector<char>(100,'#'));
  rep(i,50) ans.emplace_back(vector<char>(100,'.'));
  --a; --b;
  rep(i,50){
    if(a==0)break;
    if(i%2)continue;
    rep(j,100){
      if(a==0)break;
      if(j%2)continue;
      ans[i][j] = '.';
      --a;
    }
  }
  rep(i,50){
    if(b==0)break;
    if(i%2)continue;
    rep(j,100){
      if(b==0)break;
      if(j%2)continue;
      ans[99-i][j] = '#';
      --b;
    }
  }
  cout << "100 100" << endl;
  rep(i,100){
    rep(j,100) cout << ans[i][j]; cout << endl;
  }
}