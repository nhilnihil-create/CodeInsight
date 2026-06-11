#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;

int main() {
  int n;
  cin >> n;
  multiset<int> st;
  rep(i,n) {
    int d;
    cin >> d;
    st.insert(d);
  }

  int m;
  cin >> m;

  int ok = 1;

  while (m--) {
    int t;
    cin >> t;
    if (st.find(t) == st.end()) ok = 0;
    else {
      st.erase(st.find(t));
    }
  }
  cout << (ok ? "YES" : "NO") << endl;
  return 0;
} 