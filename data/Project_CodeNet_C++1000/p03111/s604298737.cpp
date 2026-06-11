#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;
typedef long long ll;

void chmin(int &a, int b) { if (a > b) a = b; }

// コードはここから
int N, A, B, C;
int L[10];

int rec(int i, int a, int b, int c){
  if (i==N){
    if (a==0 || b==0 || c==0) return 1000000;
    else return abs(A-a) + abs(B-b) + abs(C-c);
  }

  // 注目している竹を使わない場合
  int res = rec(i+1, a, b, c);

  // 最初に使う竹を選ぶ場合は合成ではない
  // 竹が選ばれるのが2回目以降であれば10ポイントを消費する
  chmin(res, rec(i+1, a+L[i], b, c) + (a>0 ? 10:0));
  chmin(res, rec(i+1, a, b+L[i], c) + (b>0 ? 10:0));
  chmin(res, rec(i+1, a, b, c+L[i]) + (c>0 ? 10:0));

  return res;
}

int main(){
  cin >> N >> A >> B >> C;
  rep(i, N) cin >> L[i];

  cout << rec(0,0,0,0) << endl;
}
