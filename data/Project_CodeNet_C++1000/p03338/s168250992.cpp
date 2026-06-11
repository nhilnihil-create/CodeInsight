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

int f(string s, ll a)
{
  int ans = 0;
  for(char c = 'a'; c <= 'z'; c++) {
    bool ok1 = false, ok2 = false;
    for(ll i = 0; i < s.size(); i++) {
      if(s[i] == c) {
	if(i < a) {
	  ok1 = true;
	} else {
	  ok2 = true;
	}
      }
    }
    if(ok1 == true && ok2 == true) ans++;
  }
  return ans;
}


int main(void)
{
  ll n; cin >> n;
  string s; cin >> s;
  ll ans = 0;

  REP(i, s.size()) {
    ll cnt = f(s, i);
    if(cnt > ans) ans = cnt;
  }
  
  cout << ans << endl;
}
