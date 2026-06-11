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
//#define int long long
using namespace std;

typedef long double ld;
typedef unsigned int ui;
typedef pair<int,int> pii;
typedef tuple<int, int, int> tiii;
typedef unsigned long long ull; 
typedef vector<int> vi;
typedef vector<long double> vd;
const int inf = 1e9;
const long long INF = 1e18;
const int M = 1e9 + 7;
//__int128


signed main() {
  // freopen("in.txt", "r", stdin);
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  char nxt[333];
  nxt['L'] = 'U';
  nxt['U'] = 'R';
  nxt['R'] = 'D';
  nxt['D'] = 'L';
  int sr, sc, h, w, n;
  string s, t;
  cin >> h >> w >> n >> sr >> sc >> s >> t;
  auto ok = [&](int x, int edge) {
    int c = x;
    for(int i = 0; i < n; ++i) {
      if(s[i] == 'R') {
        ++c;
        if(c > edge) {
          return 1;
        }
      }
      if(t[i] == 'L' && c > 1) {
        --c;
      }
    }
    return 0;
  };
  const int edge[] = {w, h, w, h};
  const int bgn[] = {sc, h - sr + 1, w - sc + 1, sr};
  for(int i = 0; i < 4; ++i) {
    if(ok(bgn[i], edge[i])) {
      cout << "NO" << endl;
      return 0;
    }
    for(char &ch : s) {
      ch = nxt[ch];
    }
    for(char &ch : t) {
      ch = nxt[ch];
    }
  }
  cout << "YES" << endl;
  return 0;
}