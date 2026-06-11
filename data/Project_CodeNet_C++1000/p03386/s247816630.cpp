#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main(void) {
  ll a, b, k;
  cin >> a >> b >> k;

  set<ll> st;

  for (int i = a; i < a + k; ++i) {
    if (i <= b) {
      st.insert(i);
    }
  }
  for (int i = b - k + 1; i <= b; ++i) {
    if (i >= a) {
      st.insert(i);
    }
  }

  for (auto itr = st.begin(); itr != st.end(); ++itr) {
    cout << *itr << endl;
  }
  
  return 0;
}