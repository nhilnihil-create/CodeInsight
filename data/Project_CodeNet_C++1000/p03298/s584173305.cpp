#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for(int i=j;i<n;++i)
#define all(i) i.begin(),i.end()
#define rall(i) i.rbegin(),i.end()
#define inf 1e9
#define Puts(x) puts(x? "Yes":"No")
const int mod = 1e9 + 7;

typedef pair<int, int> pi;
typedef long long i64;

template <class T> using vt = vector<T>;
template <class T> using vvt = vector<vector<T>>;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  string s;
  cin >> n >> s;

  map<pair<string, string>, int> mp;
  rep(bit, 0, 1 << n) {
    string red = "", blue = "";
    rep(j, 0, n) {
      if(bit & (1 << j)) red += s[j + n];
      else blue += s[j + n];
    }
    mp[make_pair(red, blue)]++;
  }

  i64 ans = 0;
  rep(bit, 0, 1 << n) {
    string red = "", blue = "";
    rep(j, 0, n) {
      if(bit & (1 << j)) red = s[j] + red;
      else blue = s[j] + blue;
    }
    ans += mp[make_pair(blue, red)];
  }
  cout << ans << endl;
}
