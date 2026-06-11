#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#define rep(i, f, n) for (int i = (f); i < (int)(n); i++)
#define repe(i, f, n) for (int i = (f); i <= (int)(n); i++)
using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
  int D, N;
  cin >> D >> N;
  int s = 1;
  rep(i, 0, D) s *= 100;
  if (N <= 99)
    cout << s * N << endl;
  else
    cout << s * 101 << endl;
  return 0;
}
