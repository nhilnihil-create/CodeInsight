#include <bits/stdc++.h>
using namespace std;

#define rep(i,j,n) for(int i=(j);i<(n);i++)
#define all(i) i.begin(),i.end()
#define rall(i) i.rbegin(),i.rend()
#define INF 1e9
#define LINF 1e18
const int mod = 1e9+7;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long i64;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s;
  cin >> s;

  int k = s.size();
  rep(i, 1, s.size()) {
    if(s[i] != s[i - 1]) {
      k = min(k, max(i, (int)s.size() - i));
    }
  }
  cout << k << endl;
}
