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
  int n;
  cin >> n;
  int ans = 0,m = 0;
  rep(i,0,n) {
    int p;
    cin >> p;
    ans += p;
    m = max(m,p);
  }
  ans -= m/2;
  cout << ans << endl;
  return 0;
}
