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
 
// --------------------------------------
int n, k;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
 
  cin >> n >> k;
 
  vector<P> vp;
  REP(i, n) {
    int t, d;
    cin >> t >> d;
    vp.push_back(P(d, t));
  }
 
  sort(vp.begin(), vp.end(), greater<P>());
 
  vector<bool> used(n + 1, false);
  priority_queue<int, vector<int>, greater<int>> que;
 
  ll kind = 0;
  ll sum = 0, ans = 0;
  REP(i, k) {
    sum += (ll)vp[i].first;
    if(!used[vp[i].second]) {
      used[vp[i].second] = true;
      kind++;
    } else {
      que.push(vp[i].first);
    }
  }
 
  ans = max(ans, kind * kind + sum);
  int j = k;
 
  while(!que.empty()) {
    sum -= que.top(); que.pop();
    while(j < n) {
      if(!used[vp[j].second]) {
        used[vp[j].second] = true;
        kind++;
        sum += (ll)vp[j].first;
        ans = max(ans, kind * kind + sum);
        break;
      }
      j++;
    }
    if(j >= n) break;
  }
 
  cout << ans << endl;
}