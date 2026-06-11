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

int gcd(int a, int b) {
  if (a%b == 0) {
    return(b);
  } else {
    return(gcd(b, a%b));
  }
}

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  rep(i,0,n) cin >> a[i];
  a.pb(x);
  sort(all(a));
  vector<int> b(n);
  rep(i,0,n) {
    b[i] = a[i+1] - a[i];
  }
  int ans = b[0];
  rep(i,1,n) {
    ans = gcd(ans,b[i]);
  }
  cout << ans << endl;
  return 0;
}
