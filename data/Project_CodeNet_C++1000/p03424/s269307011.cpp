// ABC 089 B- Hina Arare
// repの練習

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < int(n); i++)

int main() {
  int N, a = 0;
  string S;
  cin >> N;

  rep(i, N) { // main関数内で書くときはrep(カウント変数名,回数)
    cin >> S;
    if (S == "Y") {
      cout << "Four" << endl; // Y がきたときのみ
      break;
    }
    a++; // ループ数をカウントしておけば、数が一致することでThree判定できる
  }
  if (a == N) {
    cout << "Three" << endl;
  }
}
