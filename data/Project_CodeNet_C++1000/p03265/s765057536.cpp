#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep_inv(i, n, m) for(int i = (int)(n); i > (int)(m); i--)
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vc = vector<char>;
using vvl = vector<vl>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

int main(){
  ll x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;

  ll vx = x2 - x1, vy = y2 - y1;

  cout << x2 - vy << ' ' << y2 + vx << ' ' << x1 - vy << ' ' << y1 + vx << "\n";
  
  return 0;
}
