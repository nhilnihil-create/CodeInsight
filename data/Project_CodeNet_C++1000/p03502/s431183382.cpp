#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int N, devider = 0;
  cin >> N;
  for (int n = N; n != 0; n /= 10) {
    devider += n % 10;
  }

  if (N % devider == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}