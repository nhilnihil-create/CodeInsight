#include <bits/stdc++.h>
using namespace std;

int main () {
  int N,M;
  cin >> N >> M;
  vector<int>k(M);
  vector<vector<int>> data(M, vector<int>(N));
  vector<int>p(M);
 
  for (int i = 0; i < M; i++) {
    cin >> k.at(i);
    for (int j = 0; j < k.at(i); j++) {
      cin >> data.at(i).at(j);
    }
  }
  
  for (int i = 0; i < M; i++) {
    cin >> p.at(i);
  }
  
  int sum = 0;

  // すべての選び方を試して、総和がKになるものがあるかを調べる
  for (int tmp = 0; tmp < (1 << 10); tmp++) {
    bitset<10> s(tmp);  // 最大20個なので20ビットのビット列として扱う
    
    if (N < 10 && s.test(N)) {
      break;
    }
    
    vector<int>A(M,0);

    // ビット列の1のビットに対応する整数を選んだとみなして総和を求める
    
    for (int i = 0; i < N; i++) {
      if (s.test(i)) {
        for (int j = 0; j < M; j++) {
          for (int l = 0; l < k.at(j); l++) {
            if (data.at(j).at(l) == i+1){
              A.at(j)++;
              break;
            }
          }
        }
      }
    }
    for (int i = 0; i < M; i++) {
      if (A.at(i) % 2 != p.at(i)){
        break;
      }
      else if (i == M-1){
        sum++;
      }
    }
  }
  
  cout << sum << endl;
}

  