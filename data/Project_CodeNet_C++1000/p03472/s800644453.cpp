#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
using namespace std;  
const double pi = acos(-1.0);
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;


int main() {  
  ll n, H; cin >> n >> H;
  Vl a(n), b(n);
  ll a_ma = 0;
  ll b_su = 0;
  rep(i, 0, n){
    cin >> a[i] >> b[i];
    a_ma = max(a_ma, a[i]);
  }
  ll cnt_b = 0;
  ll b_ma = 0;
  rep(i, 0, n){
    if(b[i] > a_ma){
      b_ma += b[i];
      cnt_b++;
    }
  }
  ll h = H - b_ma;
  if(h < 0){
    sort(ALL(b), greater<ll>());
    ll cnt = 0;
    int i = 0;
    while(H > 0){
      H -= b[i];
      cnt++;
      i++;
    }
    cout << cnt << endl;
    return 0;
  } else {
    ll cnt = cnt_b;
    cnt += h/a_ma;
    if(h%a_ma != 0) cnt++;
    cout << cnt << endl;
    return 0;
  }
  

  return 0;
}
