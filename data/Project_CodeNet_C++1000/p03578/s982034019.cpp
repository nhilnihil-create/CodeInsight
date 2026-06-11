#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define INF (long long)(1e9+7)
#define REP(i,n) for(ll i = 0; i < n; i++)
#define REP1(i,n) for(ll i = 1; i <= n; i++)

//ll d[200200], t[200200];
//ll cnt[100100100];

vector<ll> d, t;
unordered_map<ll, ll> cnt;

int main(void)
{
  ll n, m;
  
  cin >> n;
  REP(i, n) {
    int d1;
    cin >> d1;
    d.push_back(d1);
  }
 
  cin >> m;
  REP(i, m) {
    int t1;
    cin >> t1;
    t.push_back(t1);
  }
  
 REP(i, n) {
     cnt[d[i]] ++;
 }
  bool ok = true;
  REP(i, m) {
    cnt[t[i]] --;
    if(cnt[t[i]] < 0) {
      ok = false;
    }
  }
  cout << (ok?"YES":"NO") << endl;
  

}
