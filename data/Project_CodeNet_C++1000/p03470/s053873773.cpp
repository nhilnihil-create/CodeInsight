#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int n;
  cin >> n;

  set<int> st;
  rep(i,n) {
    int a; cin >> a;
    st.insert(a);
  }
  cout << (int)st.size() << '\n';
}