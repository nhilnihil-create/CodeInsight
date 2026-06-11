#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
#include<deque>
using namespace std;

using ll = long long;
const int INF = 1001001001;
const ll LLINF = 1001001001001001001;

#define rep(i,n) for (int i = 0; i < (n); ++i)

set<ll> t;
set<ll> s;

ll NearTemple(ll p)
{
  auto t1 = t.lower_bound(p);
  auto t2 = t1 == t.begin() ? t1 : prev(t1);
  ll nearTempleDistance = min(abs(*t1-p), abs(*t2-p));
  return nearTempleDistance;
}

ll NearShrine(ll p)
{
  auto s1 = s.lower_bound(p);
  auto s2 = s1 == s.begin() ? s1 : prev(s1);
  ll nearShrineDistance = min(abs(*s1-p), abs(*s2-p));
  return nearShrineDistance;
}

int main()
{
  ll a, b, q;
  cin >> a >> b >> q;
  rep(i,a) {
    ll tmp;
    cin >> tmp;
    s.insert(tmp);
  }
  rep(i,b) {
    ll tmp;
    cin >> tmp;
    t.insert(tmp);
  }
  rep(i,q) {
    ll x;
    cin >> x;
    ll ts = 0; /*先に寺*/
    ll st = 0; /*先に神社*/

    /*1.先に寺へ行く*/
    auto t1 = t.lower_bound(x);
    auto t2 = t1 == t.begin() ? t1 : prev(t1);
    ll dt1 = NearShrine(*t1) + abs(*t1-x);
    ll dt2 = NearShrine(*t2) + abs(*t2-x);
    ts = min(dt1, dt2);

    /*2.先に神社へ行く*/
    auto s1 = s.lower_bound(x);
    auto s2 = s1 == s.begin() ? s1 : prev(s1);
    ll ds1 = NearTemple(*s1) + abs(*s1-x);
    ll ds2 = NearTemple(*s2) + abs(*s2-x);
    st = min(ds1, ds2);

    cout << min(st, ts) << endl;
  }
}
