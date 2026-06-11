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
  vector<ll> D(N);
  map<ll, ll> m_D;
  for (int i = 0; i < N; i++) {
    cin >> D[i];
    if (m_D.find(D[i]) != m_D.end()) {
      m_D[D[i]]++;
    } else {
      m_D[D[i]] = 1;
    }
  }
  ll M;
  cin >> M;
  vector<ll> T(N);
  bool can = true;
  for (int i = 0; i < M; i++) {
    cin >> T[i];
    if (m_D.find(T[i]) != m_D.end() && m_D[T[i]] > 0) {
      m_D[T[i]]--;
    } else {
      can = false;
      break;
    }
  }
  string ans = (can) ? "YES" : "NO";
  cout << ans << endl;
  return 0;
}