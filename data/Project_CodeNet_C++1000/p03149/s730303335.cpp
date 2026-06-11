#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  set<int> st = {1, 9, 7, 4};
  int N;
  rep(i, 4) {
    cin >> N;
    st.erase(N);
  }

  if (st.size() == 0)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}