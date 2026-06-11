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

ll gcd(ll a, ll b) {
  if (a%b == 0) {
    return(b);
  } else {
    return(gcd(b, a%b));
  }
}

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i,0,n) cin >> a[i];
  ll ans = a[0];
  rep(i,1,n) {
    ans = gcd(ans,a[i]);
  }
  cout << ans << endl;
  return 0;
}
