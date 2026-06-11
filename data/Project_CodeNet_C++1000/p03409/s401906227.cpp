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
vector<P> pa;
vector<P> pb;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> n;
  REP(i, n) {
    int a, b;
    cin >> a >> b;
    pa.push_back(make_pair(a, b));
  }

  REP(i, n) {
    int a, b;
    cin >> a >> b;
    pb.push_back(make_pair(b, a));
  }

  sort(pa.begin(), pa.end());
  sort(pb.begin(), pb.end());

  int ans = 0;
  REP(i, n) {
    int bx = pb[i].first;
    int by = pb[i].second;

    int pos = -1;
    REP(j, pa.size()) {
      int ax = pa[j].second;
      int ay = pa[j].first;
      if(ay >= by) break;
      if(ax < bx) pos = j;
    }

    if(pos != -1){
      ans++;
      pa.erase(pa.begin() + pos);
    }
  }

  cout << ans << endl;
}
