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
  int n;
  cin >> n;
  int t = 0, x = 0, y = 0;
  rep(i,0,n) {
    int nt, nx, ny;
    cin >> nt >> nx >> ny;
    int dt = nt - t, dx = abs(nx - x), dy = abs(ny - y);
    if (dt < dx + dy) {
      cout << "No" << endl;
      return 0;
    }
    if ((dt - dx - dy) % 2 == 1) {
      cout << "No" << endl;
      return 0;
    }
    t = nt, x = nx, y = ny;
  }
  cout << "Yes" << endl;
  return 0;
}