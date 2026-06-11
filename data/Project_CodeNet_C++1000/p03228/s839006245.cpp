#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const int MAX = 510000;

int main() {
  int A, B, K;
  cin >> A >> B >> K;
  for (int i=0; i<K; i++) {
    if (i%2==0) {
      if (A%2!=0) A--;
      B += A/2;
      A /= 2;
    }
    else {
      if (B%2!=0) B--;
      A += B/2;
      B /= 2;
    }
  }
  cout << A << " " << B << endl;
}