#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;

int main() {
  ll N;
  cin >> N;
  vector<ll> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  sort(a.rbegin(), a.rend());
  ll alice = 0, bob = 0;
  for (int i = 0; i < N; i++) {
    if (i % 2 == 0)
      alice += a[i];
    else
      bob += a[i];
  }
  cout << alice - bob << endl;
  return 0;
}