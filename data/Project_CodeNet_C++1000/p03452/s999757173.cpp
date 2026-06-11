#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
#define REP(i, limit) for(int i=0; i< limit; ++i)
#define LINT long long
class unionfind{
  public:
  int Num;
  vector<int> par; //親の番号
  vector<int> height; //木の高さ(ランク)
  vector<int> diff_weight; //ノードの重さ

  unionfind(int N):
    par(vector<int>(N, 0)), height(vector<int>(N, 0)), diff_weight(vector<int>(N, 0)), Num(N) {}


  //初期化
  void init(){
    REP(i, Num){
      par[i] = i;
    }
  }

  //xの親番号を返す、再帰処理あり
  int root(int x){
    if(par[x] == x) return x;
    else{
      int r = root(par[x]);
      diff_weight[x] += diff_weight[par[x]];
      par[x] = r;
      return r;
    }
  }

  //重みを求める
  int weight(int x){
    root(x);
    return diff_weight[x];
  }

  //xとyの距離
  int diff(int x, int y){
    return diff_weight[y] - diff_weight[x];
  }

  //xとyの親番号が同一か判定する
  bool same(int x, int y){
    return root(x) == root(y);
  }

  //xとyのある木を結合する
  bool unite(int x, int y, int w){
    w = w + weight(x) - weight(y);
    x = root(x);
    y = root(y);
    if(x == y) return false; //親が同一なら結合済み。

    if(height[x] < height[y]) {
      par[x] = y;
      diff_weight[x] = -1*w;
      return true;
    }
    else {
      par[y] = x;
      if(height[x] == height[y]) height[x]++;
      diff_weight[y] = w;
      return true;
    }
  }
};

int main(){
  int N, M;
  cin >> N >> M;
  int l, r, d;
  if(!M){
    cout<<"Yes"<<endl;
    return 0;
  }
  unionfind UN(N);
  UN.init();

  REP(i, M){
    cin >>l>>r>>d;
    --l;
    --r;
    if(UN.unite(l, r, d))continue;
    else{
      if(d == UN.diff(l, r)) continue;
      else{
        cout<<"No"<<endl;
        return 0;
      }
    }
  }

  cout << "Yes" << endl;

  return 0;
}
