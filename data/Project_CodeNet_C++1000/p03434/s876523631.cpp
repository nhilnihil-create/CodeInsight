#include <iostream>
#include <algorithm>

#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;

int main(void){
  int N;
  cin >> N;
  int a[N];
  rep(i, N)
    cin >> a[i];
  //入力終了

  sort(a, a+N, greater<int>());

  int Alice_p = 0, Bob_p = 0;

  //大きい点から順に足していく
  rep(i, N){
    Alice_p += a[i++];
    //Nが奇数だとBobの番が最後は来ない
    if(i<N)
      Bob_p += a[i];
  }

  //解答
  cout << Alice_p - Bob_p << endl;
  

  return 0;
}
