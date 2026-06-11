#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main () {
  int N;
  cin >> N;
  vector<LL>A(N);
  vector<LL>a(N);
  vector<LL>b(N);
  LL sum = 0;
  for (int i = 0; i < N; i ++) cin >> a[i];
  for (int i = 0; i < N; i ++) cin >> b[i];
  for (int i = 0; i < N; i ++) {
    A[i] = b[i] - a[i];
    sum += A[i];
  }
  LL sum_ = sum;
  for (int i = 0; i < N; i ++) {
    if (A[i] < 0) {
      if (sum_ < -A[i]) {
        cout << "No" << endl;
        return 0;
      }
      sum_ += A[i];
      A[i] = 0;
    }
  }
  for (int i = 0; i < N; i ++) {
    if (A[i] % 2) {
      if (sum_ == 0ll) {
        cout << "No" << endl;
        return 0;
      }
      sum_ --;
      A[i] ++;
    }
  }
 // cout << sum << endl;
  //for (int i = 0; i < N; i ++) cout << A[i] << endl;
  cout << "Yes" << endl;
}

