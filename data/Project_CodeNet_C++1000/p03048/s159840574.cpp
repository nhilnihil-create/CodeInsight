#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int INF = 1000000001;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int main() {
  int r, g, b, n;
  cin >> r >> g >> b >> n;

  int ans = 0;
  for(int i = 0; i <= n; ++i){
    for(int j = 0; j <= n; ++j){
      int ball = n - i * r - j * g;
      if(ball >= 0 && ball % b == 0){
        ans++;
      }
    }
  }

  cout << ans << endl;
  return 0;
}
