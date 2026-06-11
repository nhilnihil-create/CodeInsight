#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;

int main() {
int h,w;
cin >> h >> w;
vector<string> a(h);
vector<vector<int>> d = {{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1}};
rep(i,h) cin >> a.at(i);
rep(i,h)rep(j,w)if(a.at(i).at(j) == '.'){
    int cnt = 0;
    rep(k,8){
      int x = i +d.at(k).at(0);
      int y = j +d.at(k).at(1);
      if(x >= 0 && x < h && y >= 0 && y < w && a.at(x).at(y) == '#') cnt++;     
      }
      a.at(i).at(j) = '0' + cnt;
    }

rep(i,h) cout << a.at(i) << endl;
 }
