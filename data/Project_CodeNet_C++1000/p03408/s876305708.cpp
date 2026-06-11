#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = pair<ll,ll>;

using pqg = priority_queue<ll,vector<ll>, greater<ll> >; // 1,3,5..
using pql = priority_queue<ll,vector<ll> >; //5, 3, 1...

using pqg_p = priority_queue<P,vector<P>, greater<P> >; // 1,3,5..
using pql_p = priority_queue<P,vector<P> >; //5, 3, 1...

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)


int main() {
	cin.tie(0);
  ios::sync_with_stdio(false);

  int N,M;
  cin >> N;

  map<string,ll> s;
  map<string,ll> r;

  REP(i,N) {
    string st;
    cin >> st;
    s[st]++;
  }

  cin >> M;
  REP(i,M) {
    string st;
    cin >> st;
    r[st]++;
  }

  ll ans = 0;
  for(auto i: s) {
    ans = max(ans, i.second - r[i.first]);
  }

  cout << ans << "\n";


}
