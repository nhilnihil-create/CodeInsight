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
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> n;

  int ma = -INF, mi = INF, mapos, mipos;
  bool m_f = false, p_f = false;
  REP(i, n) {
    int a;
    cin >> a;
    if(a > 0) p_f = true;
    if(a < 0) m_f = true;
    if(ma < a) {
      ma = a;
      mapos = i + 1;
    }
    if(mi > a) {
      mi = a;
      mipos = i + 1;
    }
  }

  if(m_f && p_f) {
    cout << (n - 1) + (n - 1) << endl;
    if(abs(ma) >= abs(mi)) {
      if(m_f && p_f) FOR(i, 1, n + 1) if(i != mapos) cout << mapos << " " << i << endl;
      FOR(i, 1, n) cout << i << " " << i + 1 << endl;
    } else {
      if(m_f && p_f) FOR(i, 1, n + 1) if(i != mipos) cout << mipos << " " << i << endl;
      for(int i=n; i>1; i--) cout << i  << " " << i - 1 << endl;
    }
  } else {
    cout << (n - 1) << endl;
    if(p_f) {
      FOR(i, 1, n) cout << i << " " << i + 1 << endl;
    } else {
      for(int i=n; i>1; i--) cout << i  << " " << i - 1 << endl;
    }
  }
}
