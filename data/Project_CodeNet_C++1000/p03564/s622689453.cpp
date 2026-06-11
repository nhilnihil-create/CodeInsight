#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  int N, K;
  cin >> N >> K;
  int sum = 1;
  rep(i, N) {
    if(sum < K) {
      sum *= 2;
    }
    else {
      sum += K;
    }
  }
  cout << sum << endl;
}