#include <bits/stdc++.h>
using namespace std;

// bitsetでフラッグ管理

int main() {
  int N;
  cin >> N;
  
  bitset<101> flag;
  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;
    flag.set(num);
  }
  
  cout << flag.count() << endl;
}