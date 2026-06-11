#include <bits/stdc++.h>
using namespace std;

int main(){
  using coord= pair<int64_t, int64_t>;
  // 入力
  int H,W,D,buf;
  cin >> H >> W >> D;
  const int N= H* W;
  const int Nlen= N/D+ 1;

  vector<coord> data(N);
  for(int64_t i=0; i<H; i++){
    for(int64_t j=0; j<W; j++){
      cin >> buf;
      buf--; // 1-indexed -> 0-indexed
      data.at(buf)= make_pair(i, j);
    }
  }

  // 前処理として累積和を計算
  vector<vector<int64_t>> cumsums(D, vector<int64_t>(Nlen));

  auto dist= [](coord p1, coord p2){
    return abs(p1.first- p2.first)+ abs(p1.second- p2.second);
  };
  for(int r=0; r<D; r++){
    for(int q=1; q<Nlen; q++){
      int diff= (q*D+ r < N) ? dist(data.at(q*D+ r), data.at((q-1)*D+ r))
                             : 0;

      cumsums.at(r).at(q)= cumsums.at(r).at(q-1)+ diff;
    }
  }

  // クエリ処理
  int Q,left,right;
  cin >> Q;
  for(int i=0; i<Q; i++){
    cin >> left >> right;
    left--; right--; // 1-indexed -> 0-indexed

    cout << cumsums.at(right% D).at(right/D)- cumsums.at(left% D).at(left/D) << endl;
  }
}