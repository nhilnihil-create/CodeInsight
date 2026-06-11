#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> P;

P merge(P a,P b) {
  P ret;
  int c[4] = {a.first,a.second,b.first,b.second};
  sort(c,c+4);
  ret.first = c[3];ret.second = c[2];
  return ret;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(1 << n,0);
  vector<P> ans(1 << n);
  for (int i = 0;i < (1 << n);++i) {
    cin >> a[i];
    ans[i].first = a[i];
  }

  for (int i = 0;i < n;++i) for (int j = 0;j < (1 << n);++j) if (j&(1 << i)) ans[j] = merge(ans[j],ans[j^(1 << i)]);

  int m = 0;
  for (int i = 1;i < (1 << n);++i) {
    m = max(ans[i].first+ans[i].second,m);
    cout << m << endl;
  }
  return 0;
}