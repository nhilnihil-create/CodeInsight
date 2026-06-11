#include <cstdio>
#include <cassert>
#include <algorithm>    
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <bitset>
#define pb push_back
#define mk make_pair
#define eb emplace_back
#define eps 1e-8
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define int long long
using namespace std;

typedef long double ld;
typedef unsigned int ui;
typedef pair<int,int> pii;
typedef tuple<int, int, int> tiii;
typedef unsigned long long ull; 
typedef vector<int> vii;
typedef vector<long double> vd;
const int inf = 1e9;
const int INF = 1e18;
const int M = 1e9 + 7;
//__int128


signed main()
{
  // freopen("in.txt", "r", stdin);
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int n;
  cin >> n;
  const int maxn = 2e6;
  static char s[maxn];
  cin >> (s + 1);
  static int sc[maxn], mc[maxn];
  for(int i = 1; i <= n; ++i) {
    sc[i] = sc[i - 1];
    if(s[i] == 'C') {
      sc[i]++;
    }
  }
  int q;
  cin >> q;
  while(q--) {
    int k, m = 0;
    cin >> k;
    --k;
    mc[1] = 0;
    for(int i = 1; i <= k; ++i) {
      if(s[i] == 'M') {
        mc[1] += sc[k] - sc[i];
        ++m;
      }
    }
    // cout << m << endl;
    for(int i = 2; i <= n; ++i) {
      mc[i] = mc[i - 1];
      if(s[i - 1] == 'M') {
        int r = min(n, i + k - 2);
        mc[i] -= sc[r] - sc[i - 1];
        --m;
      }
      if(i + k - 1 <= n) {
        if(s[i + k - 1] == 'M') {
          ++m;
        } else if(s[i + k - 1] == 'C') {
          mc[i] += m;
        }
      }
      // cout << mc[i] << ' ';
    }
    long long res = 0;
    for(int i = 1; i < n; ++i) {
      if(s[i] == 'D') {
        res += mc[i + 1];
      }
    }
    cout << res << endl;
  }
  return 0;
}