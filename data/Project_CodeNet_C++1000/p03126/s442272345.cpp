#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,s,n) for (int i = (s); i < (n); ++i)
#define rrep(i,n,g) for (int i = (n)-1; i >= (g); --i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define len(x) (int)(x).size()
#define dup(x,y) (((x)+(y)-1)/(y))
#define append push_back
#define Field(T) vector<vector<T>>

using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n,m;
  cin >> n >> m;
  vector<int> food(m,0);
  rep(i,0,n) {
    int k;
    cin >> k;
    rep(j,0,k) {
      int a;
      cin >> a;
      food[a-1]++;
    }
  }
  int ans = 0;
  rep(i,0,m) {
    if (food[i] == n) ans++;
  }
  cout << ans << endl;
  return 0;
}
