#include <iostream>
#define rep(i, n) for(int i=0; i<N; i++)

using namespace std;

int main(void){
  int N, K;
  cin >> N >> K;
  int A[N];
  rep(i, N)
    cin >> A[i];
  //ここまで入力

  //選べる数がK=Nのときは1回の操作で完了する
  if(N == K){
    cout << 1 << endl;
    return 0;
  }
    
  cout << ((N-1)+(K-1)-1)/(K-1) << endl;

  return 0;
}
