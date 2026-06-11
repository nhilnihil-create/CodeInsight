#include <iostream>

using namespace std;

//n^r
long long power(long long n, long long r){
  long long ans = 1;
  while(r > 0){
    if(r & 1)
      ans *= n;
    n *= n;
    r >>= 1;
  }
  return ans;
}


int main(){
  int N, K;
  cin >> N >> K;
  //入力終わり

  //このときはKの倍数は作れない
  if(2*N < K){
    cout << 0 << endl;
    return 0;
  }
  
  //K未満の数を考える
  int under;
  //Kが奇数なら題意を満たすa,b,cは存在しない
  if(K&1)
    under = 0;
  //Kが偶数なら，a,b,cは全てKで割った余りがK/2
  else
    //Km + K/2 < N となるmの数をカウント
    under = (N-K/2)/K + 1;

  //K以上N以下の数の中で，Kの倍数の個数を数える
  int over  = N/K;

  //組み合わせはそれぞれ3乗通りある
  cout << power(under, 3) + power(over, 3) << endl;
  

  return 0;
}
