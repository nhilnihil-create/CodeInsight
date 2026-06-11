#include <vector>
#include <math.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <deque>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<long, long>;
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;
#define rep(i, n) for(int i = 0; i<n; i++)
#define rep_s(i, start, n) for(int i= start;  i<n; i++)
#define ALL(a) (a).begin(), (a).end()
string alphabet_upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string alphabet_lower  = "abcdefghijklmnopqrstuvwxyz";

/*
using edge = struct {int to; ll cost;};
vector<edge> tree[limit];
ll depth[limit];

void dfs(int v, int p, ll d){
  depth[v] = d;
  //cout <<"v: " << v << endl;
  for (auto &e: tree[v]){
    //cout << "e.to: " << e.to << endl;
    if (e.to == p) continue;
    dfs(e.to, v, d+e.cost);
  }
}
*/
int keta_sum(int num){
  int dig, sum = 0;
  while(num){
    dig = num % 10;
    sum = sum + dig;
    num = num / 10;
  }
  return sum;
}


int main(void){
  ll N, A, B, W, H, C, D;
  cin >> A >> B;
  int grid[102][102];
  rep(i, 102) rep(j, 102) grid[i][j] =-1;
  rep_s(i, 1, 51) rep_s(j, 1, 101) grid[i][j] = 1;
  rep_s(i, 1, 51) rep_s(j, 1, 101) grid[i+50][j] = 0; 
  int count_a = 0, count_b = 0;
  rep_s(i,1, 50) {
    rep_s(j, 1, 101) {
      if (count_a == A-1) goto Next;
      if (grid[i-1][j]!=0 && grid[i][j-1]!=0 && grid[i+1][j]!=0 && grid[i][j+1]!=0){
        if (grid[i-1][j-1]!=0 && grid[i-1][j+1]!=0 && grid[i+1][j-1]!=0 && grid[i+1][j+1]!=0){
          grid[i][j] = 0;
          count_a++;
         
        }
      }
    }
  }
  Next:
  rep_s(i,52, 101) {
    rep_s(j, 1, 101) {
      if (count_b == B-1) goto finished;
      if (grid[i-1][j]!=1 && grid[i][j-1]!=1 && grid[i+1][j]!=1 && grid[i][j+1]!=1){
        if (grid[i-1][j-1]!=1 && grid[i-1][j+1]!=1 && grid[i+1][j-1]!=1 && grid[i+1][j+1]!=1){
          grid[i][j] = 1;
          count_b++;
        }
      }
    }
  }
  finished:
  cout << 100 << " " << 100 << endl;
  rep_s(i, 1, 101){
    rep_s(j, 1, 101){
      if (grid[i][j] == 0) cout << ".";
      else if (grid[i][j] == 1) cout <<"#";
    }
    cout << endl;
  }
}
