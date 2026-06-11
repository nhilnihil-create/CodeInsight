#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

bool compare_by_b(P a, P b) {
  if(a.second != b.second){
    return a.second < b.second;
  } else {
    return a.first < b.first;
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<P> r(m);

  rep(i, m) {
    int a, b;
    cin >> a >> b;
    P p(a, b);
    r[i] = p;
  }

  // 右端を昇順でSortする
  sort(r.begin(), r.end(), compare_by_b);

  int cnt = 0;
  int prev = -1;
  rep(i, m) {
    P p = r[i];

    // すでに切断済みならSkip
    // 切断済み → a が prev 以下の場合
    if(p.first <= prev) {
      continue;
    }

    // 右端の一つ前の箇所を切断する
    prev = p.second - 1;
    cnt++;
  }

  cout << cnt << endl;
  return 0;
}
