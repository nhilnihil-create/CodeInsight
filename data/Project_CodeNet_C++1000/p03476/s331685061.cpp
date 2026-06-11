#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
  if (n == 1) return false;
  
  bool res = true;
  
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      res = false;
      break;
    }
  }
  
  return res;
}

int main() {
  int Q;
  cin >> Q;
  
  
  vector<int> a(100010, 0);
  
  for (int i = 1; i < 100000; i += 2) {
    if (isPrime(i) && isPrime((i+1)/2)) {
      a[i] = 1;
    }
  }
  
  // 累積和
  vector<int> sum(100001, 0);
  for (int i = 0; i < 100000; i++) {
    sum[i+1] = sum[i] + a[i];
  }
  
  
  for (int i = 0; i < Q; i++) {
    int l, r;
    cin >> l >> r;
    
    cout << sum[r+1] - sum[l] << endl;
  }
}