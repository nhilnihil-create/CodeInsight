#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = pair<ll,ll>;

using pqg = priority_queue<ll,vector<ll>, greater<ll> >; // 1,3,5..
using pql = priority_queue<ll,vector<ll> >; //5, 3, 1...

using pqg_p = priority_queue<P,vector<P>, greater<P> >; // 1,3,5..
using pql_p = priority_queue<P,vector<P> >; //5, 3, 1...

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REP1(i,n) for(int i=1, i##_len=(n); i<i##_len; ++i)
#define REPS(i,s,n) for(auto i=s, i##_len=(n); i<i##_len; ++i)

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define ALL(a)  (a).begin(),(a).end()

vector<P> v;

int dist(int i,int j) {
  return  (v[i].F -v[j].F) * (v[i].F -v[j].F) +(v[i].S -v[j].S) *(v[i].S -v[j].S);
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(false);

  ll N;

  cin >> N;
  vector<ll> a;
  vector<ll> b;
  vector<ll> c;


  REP(i,N) {
    ll t;
    cin >> t;
    a.PB(t);
  }
  a.PB(1000000001);

  REP(i,N) {
    ll t;
    cin >> t;
    b.PB(t);
  }
  b.PB(1000000001);

  REP(i,N) {
    ll t;
    cin >> t;
    c.PB(t);
  }
  c.PB(1000000001);

  sort(ALL(a));
  sort(ALL(b));
  sort(ALL(c));

  vector<ll> po(N);


  ll t = 0;
  REP1(i, N+1) {
    t += c.end() - upper_bound(ALL(c), b[N-i]) - 1;
    po[N-i] = t;
  }


  ll ans=0;
  REP(i,N) {
    auto u = upper_bound(ALL(b), a[i]);
    if(*u ==  1000000001) break;
    ans += po[u - b.begin()];
  }
  

  cout << ans << endl;

}
