#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i <= n; i++)
#define FORR(i, m, n) for(int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define ll long long
#define pb(a) push_back(a)

ll mod = 1e9 + 7;



int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n, p;
  cin >> n >> p;

  ll ans = 1, a = 2, rec = 0;

  vector<ll> pn, sn;

  ll tmp = p;

  while(tmp >= a * a){
    if(p % a == 0){
      rec++;
      p /= a;
    }
    else{
      if(rec){
        pn.pb(a);
        sn.pb(rec);
      }
      if(a == 2) a++;
      else a += 2;
      rec = 0;
    }
  }

  pn.pb(p);
  sn.pb(1);

  REP(i, pn.size()){
    ll res = sn[i] / n;
    REP(j, res) ans *= pn[i];
  }

  /*
  cout << pn.size() << endl;

  REP(i, pn.size()){
    cout << pn[i] << " " << sn[i] << endl;
  }
  */

  cout << ans << endl;

  return 0;
}
