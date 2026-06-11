#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int, int>;
typedef vector<int> vi;

const int INF = 10000000;

int N;
int A[210];

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) cin >> A[i];

  int res = INF;

  for (int i = 0; i < N; i++) {
    int count = 0;

    while (A[i] % 2 == 0) {
      A[i] /= 2;
      ++count;
    }

    if (res > count) res = count;
  }
  cout << res << endl;

  return 0;
}