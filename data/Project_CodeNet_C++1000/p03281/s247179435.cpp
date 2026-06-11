#include <bits/stdc++.h>
#include <set>
#include <queue>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++) 
#define reps(i, s, n) for (int i = s; i < (int)(n); i++) 
#define ll long long
#define ld long double
#define repl(i, n) for (ll i = 0; i < (ll)(n); i++) 
#define repsl(i, s, n) for (ll i = s; i < (ll)(n); i++)  
#define outdeb(fir, sec, thr) cout << fir << ":" << sec << ":" << thr << endl

int main()
{
  ll n;
  cin >> n;

  ll ans = 0;
  for(ll i = 1; i <= n; i+=2)
  {
    ll divs = 0;
    for(ll j = 1; j <= n; j++)
    {
      if(i % j == 0)divs++;
    }
    if(divs == 8) ans++;
  }
  cout << fixed << ans << endl; 

  return 0;
}