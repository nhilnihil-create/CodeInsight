#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;

int N=0, K=0, score=0;
double a, ans = 0;

int main(){
  cin >> N >> K;
  // 係数の計算をしておく
  a = 1.0 / N;
  rep(n, N){
    // 0.5が何回掛けられるかを保存しておく変数
    double b = 1.0;
    // 現在のスコアを保存する変数
    // 最初にn+1の目が出たという状況
    score = n+1;
    // すぬけ君が勝つのはscoreがKを上回ったとき
    // それまでwhileを回し続ける
    // 各試行に対してコインが表を出し続ける確率を求めるためにbに0,5をかけていく（2で割っていく）
    while (score < K){
      score *= 2;
      b /= 2;
    }
    // n+1の目が出たときの確率を足しあげていく
    ans += a * b;
  }
  // 出力するときには誤差に注意
  // サンプルでは小数点以下12桁まで出力していたのでそれに習う
  printf("%.12f\n", ans);
}