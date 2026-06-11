#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  int A[N];

  rep(cnt, N) {
    cin >> A[cnt];
  }
  
  int num = 0;
  while(1) {
    int sum = 0;
    rep(cnt, N) {
      sum += A[cnt] % 2;
      A[cnt] /= 2;
    }
    
    if (sum == 0) {
      num++;
    } else {
      break;
    }
  }
  
  cout << num << endl;
}