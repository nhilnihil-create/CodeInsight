#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;

int N=0, P=0;
// レストラン名
string S;
// ソートの順番通りにpairの配列を生成
// <<レストラン名, 点数>, 番号>
pair<pair<string, int>, int> R[150];

int main(){
  cin >> N;
  rep(n, N){
    cin >> S >> P;
    // 配列に格納
    R[n] = make_pair(make_pair(S, -P), n);
  }
  // 配列のそーとはbegin, endを使えないので注意
  sort(R, R+N);
  rep(i, N){
    // 0インデックスを1インデックスに変換
    cout << R[i].second + 1 << endl;
  }
}