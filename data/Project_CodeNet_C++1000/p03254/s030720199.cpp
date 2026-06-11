#include <bits/stdc++.h>
using namespace std;

#define println(msg) cout << msg << endl
#define sort_vec(vec) sort(vec.begin(), vec.end()) 

int main() {
  // 入力
  int N, x;
  cin >> N >> x;

  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a.at(i);
  }
  
  // 計算
  sort_vec(a);

  int count = 0;
  for (auto i = a.begin(); i != a.end(); i++) { 
    x -= *i;
    count++;
    
    if (x < 0) {
      count--;
      break;
    }
  }
  
  if (count > 0 && x > 0) {
    count--;
  }

  // 出力
  println(count);
}
