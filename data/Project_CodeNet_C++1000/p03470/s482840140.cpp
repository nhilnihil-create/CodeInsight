#include <bits/stdc++.h>
using namespace std;

/* 
この問題は、異なる値がいくつあるか、と捉えられる。
setで重複なしの集合が作れるので、その集合のサイズを出力すれば良い。
*/

int main() {
  int N;
  cin >> N;
  
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  
  set<int> values;
  for (int i = 0; i < N; i++) {
    values.insert(A.at(i));
  }
  
  cout << values.size() << endl;
}