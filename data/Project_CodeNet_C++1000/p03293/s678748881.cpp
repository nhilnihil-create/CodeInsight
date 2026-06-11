#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,s,n) for (int i = (s); i < (n); ++i)
#define rrep(i,n,g) for (int i = (n)-1; i >= (g); --i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define len(x) (int)(x).size()
#define dup(x,y) (((x)+(y)-1)/(y))
#define pb push_back
#define Field(T) vector<vector<T>>
using namespace std;
using ll = long long;
using P = pair<int,int>;

vector<int> makeTable(string s) {
  int n = s.size();
  vector<int> ret(n+1);
  ret[0] = -1;
  int j = -1;
  rep(i,0,n) {
    while(j >= 0 && s[i] != s[j]) j = ret[j];
    ret[i+1] = ++j;
  }
  return ret;
}

// 文字列sの部分文字列が文字列wと一致する場所を調べる
vector<int> kmp(string s, string w) {
  vector<int> table = makeTable(w), ret;
  int m = 0, i = 0, n = s.size();
  while(m+i < n) {
    if (w[i] == s[m+i]) {
      if (++i == (int)(w.size())) {
        ret.push_back(m);
        m = m+i-table[i];
        i = table[i];
      }
    } else {
      m = m+i-table[i];
      if (i > 0) i = table[i];
    }
  }
  return ret;
}

int main() {
  string s,t;
  cin >> s >> t;
  s += s;
  vector<int> ans = kmp(s,t);
  if (!ans.empty()) cout << "Yes" << "\n";
  else cout << "No" << "\n";
  return 0;
}
