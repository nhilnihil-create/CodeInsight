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

int f(int n) {
  int res = 0;
  while(n > 0) {
    res += n % 10;
    n /= 10;
  }
  return res;
}

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  int ans = 0;
  rep(i,1,n+1) {
    int k = f(i);
    if (a <= k && k <= b) ans += i;
  }
  cout << ans << endl;
  return 0;
}