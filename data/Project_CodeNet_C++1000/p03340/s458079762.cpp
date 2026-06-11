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
using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define RREP(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,k,n) for(int i=(k);i<(int)(n);i++)
#define all(i,n) (i),(i+n)

int dx4[4]={1,0,-1,0};
int dy4[4]={0,-1,0,1};
int dx8[8]={1,0,-1,1,-1,1,0,-1};
int dy8[8]={1,1,1,0,0,-1,-1,-1};

typedef pair<int, int> P;
typedef pair<string, int> SP;
typedef long long ll;

const int INF = 1e9;
const ll LLINF = 1e18;
const int MAX_V = 1e6+1;
const ll mod = 1000000007;

// --------------------------------------
int n;
int a[200005];
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> n;
  REP(i, n) cin >> a[i];

  int l = 0, r = 0, sum = 0;
  ll ans = 0;
  while(r < n || l < n) {
    if((a[r] + sum) == (a[r] ^ sum) && r < n) {
      sum = sum ^ a[r];
      r++;
    } else {
      ans += r - l;
      sum = sum ^ a[l];
      l++;
    }
  }

  cout << ans << endl;
}
