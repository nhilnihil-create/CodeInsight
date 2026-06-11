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

int main() {
  vector<vector<int>> c(3,vector<int>(3));
  rep(i,0,3) cin >> c[0][i];
  rep(i,1,3) rep(j,0,3) {
    cin >> c[i][j];
    c[i][j] -= c[0][j];
  }
  if (c[1][0] == c[1][1] && c[1][1] == c[1][2]) {
    if (c[2][0] == c[2][1] && c[2][1] == c[2][2]) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
