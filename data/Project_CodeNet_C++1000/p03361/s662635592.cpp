#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <chrono>
#include <random>
#include <functional>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
typedef long long ll;

using ipair = pair<int, int>;

ll INF = 1e16+7;

bool operator>(const ipair a,const ipair b){return a.first > b.first;}


int H, W;

bool check(vector<vector<char>> field){

  vector<int> dx = {0, 0, 1,-1};
  vector<int> dy = {1,-1, 0, 0};

  rep(h, H){
    rep(w, W){
      if(field[h][w] == '.') continue;

      bool ok = false;
      rep(i, 4){
        int nh = h + dy[i];
        int nw = w + dx[i];

        if(0 <= nh && nh < H && 0 <= nw && nw < W){
          if(field[nh][nw]=='#'){
            ok = true;
          }
        }
      }

      if(!ok){
        return false;
      }
    }
  }

  return true;
} 


int main(){
  cin >> H >> W;
  vector<vector<char>> field(H, vector<char>(W, '.'));

  rep(i, H){
    rep(j, W){
      cin >> field[i][j];
    }
  }

  if(check(field)){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }

  return 0;
}
