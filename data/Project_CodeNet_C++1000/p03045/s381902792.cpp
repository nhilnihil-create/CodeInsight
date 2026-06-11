#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
vector<int> par(1000000);//それぞれの頂点の親,最大値をsizeにする
vector<int> dis(1000000);//ランク
vector<int> si(1000000);
int n;
class union_find{
  public:
  void init(){
    for(int i = 0;i < n;i++){
      par[i] = i;//最初、親は自分自身とする
      dis[i] = 0;
      si[i] = 1;
    }
  }
  //木の根を求める
  int root(int x){
    if(par[x] == x){
      return x;
    }
    else{
      return par[x] = root(par[x]);
    }
  }
  //xとyが同じ集合に属すか否か
  bool same(int x,int y){
    //cout << x << " " << y << endl;
    return (root(x) == root(y));
  }
  //xとyの属する集合を併合
  void unite(int x,int y){
    x = root(x);
    y = root(y);
    if(x == y){
      //si[x] = 0;
      return;
    }
    if(dis[x] < dis[y]){
      par[x] = y;
      si[x] = 0;
    }
    else{
      par[y] = x;
      if(dis[x] == dis[y])dis[x]++;
      si[y] = 0;
    }
  }
};

//union_find tree;
//tree.init() //これで初期化
//tree.unite(a,b) //aとbのグループを併合
//tree.same(a,b) //aとbが同じグループか(trueかfalse)

int main(){
  ll m;
  cin >> n >> m;
  union_find tree;
  tree.init();
  for(int i = 0;i < m;i++){
    ll x,y,z;
    cin >> x >> y >> z;
    x--,y--;
    tree.unite(x,y);
    //cout << x << " " << y << endl;
  }
  ll res = 0;
  //vector<bool> seen(n);
  for(int i = 0;i < n;i++){
    if(si[i] != 0)res++;
    //cout << si[i] << " ";
  }
  //cout << endl;
  cout << res << endl;
}