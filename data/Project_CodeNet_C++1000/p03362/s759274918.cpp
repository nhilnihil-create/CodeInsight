#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const int MAX = 510000;

// 素数判定
bool prime (int i) {
  bool can = true;
  for (int j=2; j<=sqrt(i); j++) {
    if (i%j==0) {
      can = false;
      break;
    }
  }
  return can;
}

int main() {
  int N;
  cin >> N;
  vector<int> a;
  for (int i=2; i<=55555; i++) {
    if (prime(i)&&i%5==1) a.push_back(i);
  }
  for (int i=0; i<N; i++) {
    if (i==N-1) cout << a[i] << endl;
    else cout << a[i] << " ";
  }
}