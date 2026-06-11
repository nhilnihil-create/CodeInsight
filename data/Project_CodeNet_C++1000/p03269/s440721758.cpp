#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i,s,e) for(int (i) = (s);(i) <= (e);(i)++)
#define all(x) x.begin(),x.end()

int L;

struct edge {
  int from, to, cost;
};

int main() {
  cin >> L;
  int N = log2(L) + 1;
  vector<edge> ans;
  for(int i = 1;i < N;i++) {
    ans.push_back({ i, i + 1, 0 });
    ans.push_back({ i, i + 1, (1 << (i - 1)) });
  }

  for(int i = N - 1;i >= 1;i--) {
    if(L - (1 << (i - 1)) >= (1 << (N - 1))) {
      ans.push_back({ i, N, L - (1 << (i - 1)) });
      L = L - (1 << (i - 1));
    }
  }

  cout << N << " " << ans.size() << endl;
  for(auto e: ans) {
    cout << e.from << " " << e.to << " " << e.cost << endl;
  }
}
