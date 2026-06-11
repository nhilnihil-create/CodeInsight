#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void solve() {
  string s;
  cin >> s;
  int n = s.size();
  int cnt1 = 0;
  rep(i,n) {
    if (i % 2 == 0 && s[i] != '0') cnt1++;
    if (i % 2 == 1 && s[i] != '1') cnt1++;
  } 
  int cnt2 = 0;
  rep(i,n) {
    if (i % 2 == 0 && s[i] != '1') cnt2++;
    if (i % 2 == 1 && s[i] != '0') cnt2++;
  } 
  cout << min(cnt1, cnt2) << endl;
}

int main() {
  solve();
  return 0;
}