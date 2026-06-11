#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
  int h, w, n;
  cin>>h>>w>>n;
  int sr,sc;
  cin>>sr>>sc;
  --sr;
  --sc;
  string s, t;
  cin>>s>>t;
  int l = 0,
      r = w - 1,
      u = 0,
      d = h - 1;

  if (s[n-1] == 'L') {
    l = 1;
  } else if (s[n-1] == 'R') {
    r = w - 2;
  } else if (s[n-1] == 'U') {
    u = 1;
  } else {
    d = h - 2;
  }
  for (int i=n-2; i>=0; i--) {
    if (t[i] == 'L') {
      r = min(r + 1, w - 1);
    } else if (t[i] == 'R') {
      l = max(l - 1, 0);
    } else if (t[i] == 'U') {
      d = min(d + 1, h - 1);
    } else {
      u = max(u - 1, 0);
    }
    if (s[i] == 'L') {
      l = l + 1;
    } else if (s[i] == 'R') {
      r = r - 1;
    } else if (s[i] == 'U') {
      u = u + 1;
    } else {
      d = d - 1;
    }
    if (l > r || u > d) {
      cout<<"NO"<<endl;
      return 0;
    }
  }
  if (sc >= l && sc <= r && sr >= u && sr <= d) {
    cout<<"YES"<<endl;
  } else {
    cout<<"NO"<<endl;
  }
}