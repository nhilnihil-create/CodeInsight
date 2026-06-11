#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;
const int MAX = 100'000;

int main() {
  int n;
  cin >> n;

  int mfe = 0, mfo = 0;
  vector<int> e(MAX, 0), o(MAX, 0);
  rep(i,0,n-1) {
    int v;
    cin >> v;
    if (i % 2 == 0) {
      e[v]++;
      if (e[mfe] < e[v]) mfe = v;
    } else {
      o[v]++;
      if (o[mfo] < o[v]) mfo = v;
    }
  }

  sort(e.begin(), e.end(), greater<int>());
  sort(o.begin(), o.end(), greater<int>());

  int e_size = (n + 1) / 2;
  int o_size = n / 2;
  if (mfe != mfo || e[0] != o[0])
    cout << e_size - e[0] + o_size - o[0] << endl;
  else
  {
    int ans1 = e_size - e[0] + o_size - o[1];
    int ans2 = e_size - e[1] + o_size - o[0];
    cout << min(ans1, ans2) << endl;
  }

  return 0;
}
