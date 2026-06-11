#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int, int>;
typedef vector<int> vi;

int N, a, b;

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a;
    b |= a;
  }

  int count = 0;
  while (b % 2 == 0) {
    b /= 2;
    ++count;
  }
  cout << count << endl;

  return 0;
}