#include <iostream>
#include <iomanip>
#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <bitset>
#include <set>
#include <stack>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define RREP(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,k,n) for(int i=(k);i<(int)(n);i++)
#define all(i,n) (i),(i+n)

int dx4[4]={1,0,-1,0};
int dy4[4]={0,-1,0,1};
int dx8[8]={1,0,-1,1,-1,1,0,-1};
int dy8[8]={1,1,1,0,0,-1,-1,-1};
int dx9[9]={0,1,0,-1,1,-1,1,0,-1};
int dy9[9]={0,1,1,1,0,0,-1,-1,-1};

typedef pair<int, int> P;
typedef pair<string, int> SP;
typedef long long ll;
typedef pair<ll, ll> PLL;

const int INF = 1e9;
const ll LLINF = 1e18;
const int MAX_V = 1e6+1;
const ll mod = 1000000007;
// << fixed << setprecision
// --------------------------------------
int n;
map<int, int> prime_factor(int n) {
  map<int, int> res;
  for(int i=2; i*i<=n; i++) {
    while(n % i == 0) {
      ++res[i];
      n /= i;
    }
  }
  if(n != 1) ++res[n];
  return res;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> n;

  map<int, int> mp;
  FOR(i, 2, n + 1) {
    auto p = prime_factor(i);
    for(auto j : p) {
      mp[j.first] += j.second;
    }
  }

  int ans = 0;
  for(auto i : mp) if(i.second >= 74) ans++;

  REP(i, mp.size()) REP(j, mp.size()) {
    if(i != j && mp[i] >= 14 && mp[j] >= 4) ans++;
  }

  REP(i, mp.size()) REP(j, mp.size()) {
    if(i != j && mp[i] >= 24 && mp[j] >= 2) ans++;
  }

  REP(i, mp.size()) REP(j, mp.size()) FOR(k, j + 1, mp.size()) {
    if(i != j && j != k && k != i && mp[i] >= 2 && mp[j] >= 4 && mp[k] >= 4) ans++;
  }

  cout << ans << endl;
}
