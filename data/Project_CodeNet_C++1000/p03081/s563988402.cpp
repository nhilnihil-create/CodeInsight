#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, q;
  cin>>n>>q;
  string s;
  cin>>s;

  char t[q], d[q];
  for (int i=0; i<q; i++) {
    cin>>t[i]>>d[i];
  }
  int cnt = 0;
  int l = -1, r = n;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    int cur = mid;
    bool ok = false;
    for (int i=0; i<q; i++) {
      if (s[cur] == t[i]) {
        if (d[i] == 'L') {
          --cur;
        } else {
          ++cur;
        }
      }
      if (cur == n) {
        ok = true;
        break;
      } else if (cur == -1) {
        break;
      }
    }
    if (ok) {
      r = mid;
    } else {
      l = mid;
    }
  }
  cnt += n - l - 1;
  l = -1;
  r = n;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    int cur = mid;
    bool ok = false;
    for (int i=0; i<q; i++) {
      if (s[cur] == t[i]) {
        if (d[i] == 'L') {
          --cur;
        } else {
          ++cur;
        }
      }
      if (cur == n) {
        break;
      } else if (cur == -1) {
        ok = true;
        break;
      }
    }
    if (ok) {
      l = mid;
    } else {
      r = mid;
    }
  }
  cnt += l + 1;
  cout<<n - cnt<<endl;
}