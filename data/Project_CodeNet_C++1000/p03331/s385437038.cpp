#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
#define INF (int)1e8
#define EPS 1e-9

using vi = vector<int>;
using vvi = vector<vi>;
using vs = vector<string>;

int findSumOfDigits(int n) {
  int sum = 0;
  while (n > 0) {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}

int main() {
  int N;
  cin >> N;

  int sum = findSumOfDigits(N);
  if (sum == 1) sum = 10;

  cout << sum << endl;
}