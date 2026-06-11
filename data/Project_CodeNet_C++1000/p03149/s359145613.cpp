#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

int main() {
  ll a;
  unordered_set<ll> st;
  rep(i, 4) cin >> a, st.insert(a);

  cout << ((st.count(1) && st.count(7) && st.count(9) && st.count(4)) ? "YES"
                                                                  : "NO")
       << endl;
  return 0;
}
