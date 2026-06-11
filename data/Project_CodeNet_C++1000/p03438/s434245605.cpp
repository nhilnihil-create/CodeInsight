#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
  ll N;
  cin >> N;
  
  vector<ll> a(N), b(N);
  
  ll sum_a = 0, sum_b = 0;; 
  
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    sum_a += a[i];
  }
  
  for (int i = 0; i < N; i++) {
    cin >> b[i];
    sum_b += b[i];
  }
  
  if (sum_b - sum_a < 0) {
    cout << "No" << endl;
    return 0;
  }
  
  ll inc = 0;
  
  
  for (int i = 0; i < N; i++) {
    if (a[i] < b[i]) {
      inc += (b[i] - a[i] + 1) / 2;
    }
  }
  
  if (inc > sum_b - sum_a) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
  
  
}


