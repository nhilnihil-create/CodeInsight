#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A;
  int count;
  int ans;
  
  cin >> N;
  
  for (int i = 0; i < N; i++) {
    cin >> A;
    count = 0;
    
    while (A % 2 == 0) {
      A /= 2;
      count++;
    }
    
    if (i == 0) {
      ans = count;
    }
    else if (ans > count) {
      ans = count;
    }
  }
  
  cout << ans << endl;
}