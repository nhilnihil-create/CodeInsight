#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

vector < pair < char, char > > v;
int n, q;
string s;

bool checkL (int idx) {
  for (auto i : v) {
    if (idx < 0) break;
    if (i.first == s[idx]) {
      if (i.second == 'L') idx--;
      else idx++;
    }
  }

  return (idx < 0);
}

bool checkR (int idx) {
  for (auto i : v) {
    if (idx > n - 1) break;
    if (i.first == s[idx]) {
      if (i.second == 'R') idx++;
      else idx--;
    }
  }

  return (idx > n - 1);
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  cin >> n >> q >> s;
  v.resize(q);
  for (auto &i : v) cin >> i.first >> i.second;

  int lo = 0, hi = n - 1, l = -1, r = n;
  while (lo <= hi) {
    int mid = (hi - lo) / 2 + lo;
    if (checkL (mid)) {
      lo = mid + 1;
      l = max (l, mid);
    } else {
      hi = mid - 1;
    }
  }

  lo = 0, hi = n - 1;
  while (lo <= hi) {
    int mid = (hi - lo) / 2 + lo;
    if (checkR (mid)) {
      hi = mid - 1;
      r = min (r, mid);
    } else {
      lo = mid + 1;
    }
  }

  cout << r - l - 1 << '\n';
}
