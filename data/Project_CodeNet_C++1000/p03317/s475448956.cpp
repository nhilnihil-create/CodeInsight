#include <iostream>
#include <math.h>
using namespace std;

/*
すべての要素を１にしたいので，区間全体を１に広げる操作をする．
１が含まれる範囲Kの区間を重なるように実行すれば良い．つまり区間の数が答えである．
mこの区間で覆える範囲は，[1, (K-1)m+1] = N
*/
int main() {
  double N, K;
  cin >> N >> K;
  
  int ans = ceil((N-1) / (K-1));
  cout << ans << endl;
  
  return 0;
}
