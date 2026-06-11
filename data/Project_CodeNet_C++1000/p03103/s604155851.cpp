#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

bool sort_by_first(const pair<ll,ll> &a, 
              const pair<ll,ll> &b) 
{ 
    return (a.first < b.first); 
} 

int main()
{
  int n,m;
  cin >> n >> m;
  vector<pair<ll, ll>> vec(n);
  REP(i, n) {
    cin >> vec[i].first >> vec[i].second;
  }
  
  sort(vec.begin(), vec.end(), sort_by_first); 
  ll amt = 0;
  unsigned long long cost = 0;
  REP(i, n) {
    if ((amt + vec[i].second) >= m) {
      ll ad = m - amt;
      cout << cost + ad * vec[i].first << endl;
      return 0;
    } else {
      amt += vec[i].second;
      cost += vec[i].first * vec[i].second;
    }
  }
  
  return 0;
}