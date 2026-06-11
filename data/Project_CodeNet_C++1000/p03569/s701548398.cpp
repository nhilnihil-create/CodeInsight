#include<bits/stdc++.h>
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int mod = 1000000007;
const int INF = 1001001001;

int main() {
  string s;
  cin >> s;
  int n = s.length();
  int l = 0, r = n - 1;
  int ans = 0;
  while (l < r) {
    if (s[l] == s[r]) {
      l++, r--;
    } else if (s[l] == 'x') {
      l++, ans++;
    } else if (s[r] == 'x') {
      r--, ans++;
    } else {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << ans << endl;
}