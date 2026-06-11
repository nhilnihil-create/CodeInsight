#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> P;
typedef vector<vector<int>> Matrix;
static const int INF = 2000000000;

int main(){
  int n;
  string s;
  cin >> n >> s;
  vector<int> l(n+2), r(n+2);
  l[0] = 0;
  r[n+1] = 0;
  rep(i, n){
    if (s[i] == 'W') l[i+1] = l[i] + 1;
    else l[i+1] = l[i];
  }
  for (int i = n-1; i >= 0; i--){
    if (s[i] == 'E') r[i+1] = r[i+2] + 1;
    else r[i+1] = r[i+2];
  }

  int ans = INF;
  for (int i = 1; i <= n; i++){
    ans = min(ans, l[i-1] + r[i+1]);
  }
  cout << ans << endl;
}