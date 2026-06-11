#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
#include<deque>
using namespace std;

using ll = long long;
const int INF = 1001001001;
const ll LLINF = 1001001001001001001;

#define rep(i,n) for (int i = 0; i < (n); ++i)

ll coun = 0;

int main()
{
  string s, t;
  cin >> s >> t;
  int ss = s.size();
  int ts = t.size();

  vector<string> l;

  rep(i, ss - ts + 1) {
    bool isMatch = true;
    rep(j, ts) {
      if (s[i + j] != t[j] && s[i + j] != '?') {
        isMatch = false;
      }
    }
    if (isMatch) {
      string tmp = s;
      rep(index, ts) {
        tmp[i + index] = t[index];
      }
      rep(index, ss) { // ? を置き換え
        if (tmp[index] == '?')
          tmp[index] = 'a';
      }
      l.push_back(tmp);
    }
  }

  sort(l.begin(), l.end());
  if (l.empty()) {
    cout << "UNRESTORABLE" << endl;
  } else {
    cout << l[0] << endl;
  }
}
