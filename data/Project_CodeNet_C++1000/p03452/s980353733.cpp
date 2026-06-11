#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
using namespace std;
#define MOD 1000000007
#define INF (1<<29)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

class WeightedUnionFind{
public:
  int n;
  vector<int> u;
  vector<Int> weight;
  WeightedUnionFind(int n = 0):n(n){
    u = vector<int>(n);
    weight = vector<Int>(n,0);
    for(int i = 0;i < n;i++)u[i] = i;
  }
  int r(int x){
    if(u[x] == x)return x;
    r(u[x]);
    weight[x] += weight[u[x]];
    return u[x] = r(u[x]);
  }

  Int dif(Int x, Int y){
    if(r(x) != r(y))return INF;
    return weight[x] - weight[y];
  }

  //x - y == w
  bool isOK(int x, int y, Int w){
    if(r(x) != r(y))return false;
    return dif(x,y) == w;
  }

  int unite(int x, int y, Int w){
    r(x);
    r(y);
    w += weight[y];
    w -= weight[x];
    x = r(x);
    y = r(y);
    u[x] = y;
    weight[x] = w;
  }
};

void ok(){
  cout << "Yes" << endl;
  exit(0);
}

void ng(){
  cout <<  "No" << endl;
  exit(0);
}

Int n, m, l, r, d;
int main(){
  cin >> n >> m;
  WeightedUnionFind wuf(n);
  for(int i = 0;i < m;i++){
    cin >> l >> r >> d;l--, r--;
    if(wuf.r(l) == wuf.r(r)){
      if(!wuf.isOK(r, l, d))ng();
    }
    else{
      wuf.unite(r, l, d);
    }
  }
  ok();
  return 0;
}