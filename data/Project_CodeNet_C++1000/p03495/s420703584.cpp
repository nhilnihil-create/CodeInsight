#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)

int main(void){
  int N, K;
  cin >> N >> K;
  int A[N];
  rep(i, N)
    cin >> A[i];
  //ここまで入力

  //整数iが何回出てくるか
  int count[N] = {0};
  rep(i, N)
    count[A[i]-1]++;

  //登場する整数が少ないものをいくつか取れば最適
  //そのまま考えたら難しいので
  //登場する整数が多いものをK種類選ぶ
  //カウントしたものをNから引けば解答になる
  sort(count, count+N, greater<>());

  //登場する整数が多いものをK種類分足す
  int ans_ = 0;
  for(int i=0; i<K; i++)
    ans_ += count[i];
  
  cout << N - ans_ << endl;

  return 0;
}
