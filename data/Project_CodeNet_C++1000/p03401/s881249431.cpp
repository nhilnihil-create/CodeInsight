#include <iostream>
#include <cmath>

using namespace std;

int main(){
  int N;
  cin >> N;
  int A[N+2];
  //実装上，初めと終わりに原点を入れる
  A[0] = 0; A[N+1] = 0;
  for(int i=1; i<N+1; i++)
    cin >> A[i];
  //ここまで入力

  //合計でいくらかかるか
  int sum = 0;
  for(int i=0; i<N+1; i++)
    sum += abs(A[i+1]-A[i] );

  //地点iを飛ばしたときに減る金額と，新しい金額
  int cancel, new_;
  for(int i=1; i<N+1; i++){
    //地点iが中継地点にあればsumから変化なし
    if(A[i-1] <= A[i] && A[i] <= A[i+1])
      cout << sum << endl;
    //そうでなければ，地点iを飛ばした金額を計算する
    else{
      cancel = abs(A[i+1] - A[i]) + abs(A[i] - A[i-1] );
      new_ = abs(A[i+1] - A[i-1] );
      cout << sum - cancel + new_ << endl;;
    }
  }

  
  
  return 0;
}
