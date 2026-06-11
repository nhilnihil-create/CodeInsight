#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MOD (long long)(1e9+7)
#define REP(i,n) for(ll i = 0; i < n; i++)
#define REP1(i,n) for(ll i = 1; i <= n; i++)

ll gcd(ll a, ll b)
{
  if(b == 0) return a;
  return gcd(b, a % b);
}

void solve()
{
  ll k, a, b; cin >> k >> a >> b;
  ll ans = 1;
  if(b - a <= 1) { //お金に変えても増えないなら
    ans += k; //k回たたく
  } else if(k >= a - 1) {
    ans += a - 1; //まずa枚まで増やす
    k -= a - 1;
    ans += (k / 2) * (b - a) + k % 2; //2回の操作でb-a枚ずつ増やしてって、1回余ってたら叩いて増やす
  } else {
    ans += k; // k回叩いてもa枚以下のとき
  }
  cout << ans << endl;
}


int main(void)
{
  // ll t; cin >> t; REP(i, t)
  solve();
}
