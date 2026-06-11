#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
#define inf (int)1e18+7

const int nmax = (int)2e5+10;
int n, h[nmax], a[nmax];
int tree[nmax];

set<pair<int, int > > myset;

void seekAndUpdate (int id ) {
  pair<int, int > pp = make_pair(h[id], a[id]);
  myset.insert(pp);
  auto it = myset.find(pp);
  if (it != myset.begin()) {
    it --;
    auto pre = it;
    it ++;
    pp.second += pre -> second;
    myset.erase(it);
    myset.insert(pp);
  }
  while (it != myset.end()) {
    it ++;
    auto tmp = it;
    if (tmp == myset.end()) break;
    it --;
    if (pp.second > tmp -> second) {
      myset.erase(tmp);
    } else {
      break;
    }
  }
}

signed main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i ++) {
    cin >> h[i];
  }

  for (int i = 1; i <= n; i ++) {
    cin >> a[i];
  }

  myset.insert(make_pair(0, 0));
  for (int i = 1; i <= n; i ++) {
    seekAndUpdate(i);
  }
  auto it = myset.end();
  it --;
  cout << it -> second << endl;

  return 0;
}