#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int INF=1000000007;

int main() {
  int n, q;
  string s;
  cin >> n >> q >> s;
  vector<int> AC(n);
  for(int i=1; i<n; i++) {
    AC[i]=AC[i-1];
    if(s[i-1]=='A'&&s[i]=='C') AC[i]++;
  }
  vector<int> ans(q);
  rep(i,q) {
    int l, r;
    cin >> l >> r;
    l--; r--;
    ans[i]=AC[r]-AC[l];
  }

  rep(i,q) cout << ans[i] << endl;
}