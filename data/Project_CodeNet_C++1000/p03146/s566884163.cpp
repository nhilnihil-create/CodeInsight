#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  int s;
  cin >> s;
  set<int> st;
  int x = s;
  while(st.count(x) == 0) {
    st.insert(x);
    if(x % 2 == 0) {
      x /= 2;
    }
    else {
      x = 3 * x + 1;
    }
  }
  cout << st.size() + 1 << endl;
  return 0;
}