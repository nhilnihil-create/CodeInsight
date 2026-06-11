#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;

  string S;
  set<string> st;
  rep(i, N) {
    cin >> S;
    st.insert(S);
  }

  if (st.size() == 3)
    cout << "Three" << endl;
  else
    cout << "Four" << endl;
}