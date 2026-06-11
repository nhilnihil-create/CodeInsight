#include <iostream>
#include <cmath>

using namespace std;

int main(void){
  long long int N, M;
  cin >> N >> M;
  //ここまで入力

  //縦か横が1マスであれば，両端以外が裏になる
  if(N == 1)
    cout << abs(M-2) << endl;
  else if(M == 1)
    cout << N-2 << endl;
  //それ以外ならば，周を除いた中心部分が裏になる
  else{
    //周のマスの数
    long long int lap = 2*N + 2*M - 4;
    //合計のますの数
    long long int sum = N*M;
    cout << sum - lap << endl;
  }
  
  return 0;
}
