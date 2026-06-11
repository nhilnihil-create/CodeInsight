#include <iostream>
#define rep(i, n) for(int i=0; i<n; i++)

using namespace std;

int main(void){
  int N, M, X;
  cin >> N >> M >> X;
  int A[M];
  rep(i, M)
    cin >> A[i];
  //入力終了

  //Xから見て左に向かうときのコストと，右のときとを計算する
  int left_cost = 0;
  int right_cost = 0;
  rep(i, M){
    //左
    if(A[i] < X)
      left_cost++;
    //右
    else
      right_cost++;
  }

  //コストの小さい方を選ぶ
  cout << min(left_cost, right_cost) << endl;

  return 0;
}
