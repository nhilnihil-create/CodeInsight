#include <bits/stdc++.h>
using namespace std;

/*
方法1: 全探索+フラッグ
方法2: 割り切れる回数が最も少ない値を見つけ、その値を割り切れる回数を出力
*/

const int INF = 10000000;
int N;
vector<int> A(210);

int main() { 
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  
  int min_divisible = INF;
  for (int i = 0; i < N; i++) {
    int count = 0;
    
    while ((A.at(i) % 2) == 0) {
      A.at(i) /= 2;
      count++;
    }
    
    if (min_divisible > count) min_divisible = count;
  }
  
  cout << min_divisible << endl;
}
