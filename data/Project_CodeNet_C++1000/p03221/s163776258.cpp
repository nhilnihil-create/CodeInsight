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

int main(void)
{
  ll n, m; cin >> n >> m;

  // string s; cin >> s;
  vector<ll> p(m), y(m) ; REP(i, m) cin >> p[i] >> y[i];
  char strbuf[100];
  vector<string> vs(m);
  REP(i, m) {
    sprintf(strbuf, "%06lld%012lld%06lld", p[i], y[i], i);
    vs[i] = strbuf;
    //    cout << vs[i] << endl;
  }
  sort(vs.begin(),vs.end());
  ll pbuf, oldp = -1, pcnt = 0;
  REP(i, m) {
    //    cout << vs[i] << endl;
    pbuf = stoll(vs[i].substr(0, 6));
    if(pbuf != oldp) {pcnt = 0; oldp = pbuf;}
    pcnt ++;
    sprintf(strbuf, "%6s%6s%06lld", vs[i].substr(18,6).c_str(), vs[i].substr(0, 6).c_str(), pcnt);
    vs[i] = strbuf;
  }
  sort(vs.begin(),vs.end());
  REP(i, m) {
    cout << vs[i].substr(6,12) << endl;
  }
  

}
