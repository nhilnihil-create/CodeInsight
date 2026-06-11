#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

map<int, int> prime_factor(int n) {
  map<int, int> ret;
  for(int i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return ret;
}

map<int, int> mp;

int num(int k)
{
  int ret = 0;
  for(auto p: mp){
    if(p.second>=k) ret++;
  }
  return ret;
}

int main()
{
  int n;
  cin >> n;
  
  for(int i=2; i<=n; i++){
    map<int, int> tmp = prime_factor(i);
    for(auto itr=tmp.begin(); itr!=tmp.end(); itr++){
      mp[itr->first] += itr->second;
    }
  }
  
  int ans = 0;
  ans += num(74);
  ans += num(24) * (num(2) - 1);
  ans += num(14) * (num(4) - 1);
  ans += num(4) * (num(4) - 1) * (num(2) - 2) / 2;
  cout << ans << '\n';
  return 0;
}
