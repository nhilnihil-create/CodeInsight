#include <bits/stdc++.h>
using namespace std;

// バケット法でユニークな値の数を数える

int main() {
  int N;
  cin >> N;
  
  vector<int> A(110);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  
  vector<int> d(110);  // 1から100(+余剰)のフラッグを格納するためのダミー配列
  for (int i = 0; i < N; i++) d.at(A.at(i))++;  // dのA[i]番目を0以上にする(フラッグ立て)
  
  int count = 0;
  for (int i = 1; i <= 100; i++) {  // 制約より、値は1から100
    if (d.at(i)) count++;  // 0でない(true)ならカウント
  }
  
  cout << count << endl;
}