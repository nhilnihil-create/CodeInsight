#include <bits/stdc++.h>
#include <set>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define contains(v, t) (find(v.begin(), v.end(), t) != v.end())
#define MOD 1000000007
using ll = long long;
using ull = unsigned long long;

int main() {
  int n;
  string s;
  cin>>n>>s;
  int ans = 0;
  for(int i = 1; i < n; i++) {
    string a = s.substr(0, i);
    string b = s.substr(i, n-i);
    set<char> sa, sb;
    rep(j, a.length()) sa.insert(a[j]);
    rep(j, b.length()) sb.insert(b[j]);
    map<char, int> m;
    int c = 0;
    for(auto j : sa) {
      if (sb.find(j) != sb.end()) c++;
    }
    ans = max(ans, c);
  }
  cout << ans;
}
