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
  int a, b, c, x;
  cin >> a >> b >> c >> x;
  int ans = 0;
  rep(i,0,a+1) rep(j,0,b+1) rep(k,0,c+1) {
    if (500*i + 100*j + 50*k == x) ans++;
  }
  cout << ans << endl;
  return 0;
}
