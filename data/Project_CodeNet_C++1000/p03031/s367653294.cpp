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

#define lpair pair<ll, ll>

int main()
{
  ll n,m;
  cin >> n >> m;
  vector<ll> rits;
  vector<ll> outs;
  repl(i, m)
  {
    ll k;
    cin >> k;
    ll d = 0;
    repl(j, k)
    {
      ll tmp;
      cin >> tmp;
      d += 1 << (tmp-1);
    }
    rits.push_back(d);
  }
  
  repl(i, m)
  {
    ll t;
    cin >> t;
    outs.push_back(t);
  }

  ll ans = 0;
  repl(i, pow(2, n))
  {
    bool isError = false;
    repl(j, m)
    {
      ll tmp = rits[j] & i;
      if(__builtin_popcountll(tmp) % 2 != outs[j] )
      {
        isError = true;
        break;
      }
    }
    if(!isError) ans++;
  }

  cout << ans << endl;

  return 0;
}