#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n; string s;
  cin >> n >> s;
  int cntE = 0, cntW = 0;
  vector<int> dpE(n), dpW(n);
  rep(i,n) {
    dpW[i] = cntW;
    if(s[i]=='E') cntE++;
    if(s[i]=='W') cntW++;
    dpE[i] = cntE;
  }

  int ans = n;

  rep(i,n) {
    int tmp = dpE[n-1] - dpE[i] + dpW[i];
    ans = min(ans, tmp);
  }
  cout << ans << endl;
  return 0;
}