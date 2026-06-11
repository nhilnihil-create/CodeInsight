#include <bits/stdc++.h>
using namespace std;

int main() {
  // 入力を受け取る
  int N;
  cin >> N;
  
  vector<int> A(N);
  for(auto i = A.begin(); i != A.end(); i++) {
    cin >> *i;
  }
  
  int count = 0;
  while (true) {
    auto ret = all_of(A.begin(), A.end(), [](int a) { return a % 2 == 0; });
    
    if (!ret) {
      break;
    }
    
    count++;
    for(auto i = A.begin(); i != A.end(); i++) {
      *i = (*i) >> 1;
    }    
  }
  cout << count << endl;
}