#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<cmath>
#include<math.h>
#include<algorithm>
#include<string.h>
#include <iomanip>
#include <sstream>
using namespace std;

int main() {
  int N, M;
  int ans = 0;

  cin >> N >> M;

  vector<int> k(M);
  vector<int> p(M);
  vector<vector<int>> s(M, vector<int>(N));
  for(int i = 0; i < M; i++){
    cin >> k[i];
    for(int j = 0; j < k[i]; j++){
      cin >> s[i][j];
    }
  }
  for(int i = 0; i < M; i++){
    cin >> p[i];
  }
  int cnt = 0;

  // {0, 1, ..., n-1} の部分集合の全探索
  for (int bit = 0; bit < (1<<N); ++bit) {
    vector<int> ss(M);//各電球に対して, onになっているスイッチ数
    // cout << "bit: " << bit << endl;

    vector<int> s_on(1);//onになっているスイッチ番号?
    int tm = 0;
    for (int i = 0; i < N; ++i) {
      if (bit & (1<<i)) { // i が bit に入るかどうか
        //onになっているスイッチを記録
        if(tm==0){
          s_on[0] = (i+1);
        }else{
          s_on.push_back((i+1)); 
        }
        // cout << "  push: "<< i+1 << ">> " << s_on[tm] << ": in size=" << s_on.size()<< endl;
        tm++;
      }
    }
    // cout << "  s_on:  ";
    // for (int i = 0; i < s_on.size(); ++i) {
    //   cout << s_on[i] << " ";
    // }
    // cout << endl;

    //各電球に対応するスイッチの内、ONのものカウント
    for(int i_k = 0; i_k < M; ++i_k){
      int tmp = 0;
      int tmpsize = s_on.size();
      for(int i_s = 0; i_s < k[i_k]; ++i_s){
        for(int tmp = 0; tmp < tmpsize; ++tmp){
          if(s[i_k][i_s] == s_on[tmp]){
            ss[i_k]++;
          }
        }
      }
    }

    int tmpcnt=0;
    for(int i_ = 0; i_ < M; ++i_){
      //ssの各結果を2で割り, pと比較
      // cout << "  " << i_ << "th ss: " << ss[i_] << endl;
      if(ss[i_]%2 == p[i_]){
        tmpcnt++;
      }
    }
    if(tmpcnt == M){
      //全部ついてる場合カウント
      cnt++;
      // cout << "  all ON" << endl;
    }
  }
  cout << cnt << endl;
}
