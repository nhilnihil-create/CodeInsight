#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

#define MOD 1000000007
#define REP(i, N) for (int i = 0; i < N; ++i)
#define REP1(i, N) for (int i = 1; i <= N; ++i)
#define RREP(i, N) for (int i = N - 1; i >= 0; --i)
#define ALL(a) a.begin(), a.end()

int main() {
  int n;
  cin >> n;
  int a[n];
  REP(i, n) cin >> a[i];
  multiset<int> st;
  REP(i, n) st.insert(a[i]);
  int ans = 0;
  while (st.size()) {
    ll p = *st.rbegin();
    st.erase(st.find(p));
    ll b = 1;
    while (b <= p) b *= 2;
    if (st.find(b - p) != st.end()) {
      ans++;
      st.erase(st.find(b - p));
    }
  }
  cout << ans << endl;
  return 0;
}