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
  set<ll> s;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  ll cnt = 0;
  for (int i = 0; i < N - 1; i++) {
    if (a[i] == a[i + 1]) {
      cnt++;
      a[i + 1] = 100001;
    }
  }
  cout << cnt << endl;
  return 0;
}