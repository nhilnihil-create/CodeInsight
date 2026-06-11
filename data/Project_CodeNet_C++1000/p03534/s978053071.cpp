#include <algorithm>
#include <bitset>
#include <cctype>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
/*----------------------------------------*/

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  string s; cin >> s;
  int a = 0, b = 0, c = 0;
  for (char ch : s) {
    if (ch == 'a') ++a;
    else if (ch == 'b') ++b;
    else ++c;
  }
  if (abs(a-b)>1||abs(b-c)>1||abs(c-a)>1) cout << "NO" << '\n';
  else cout << "YES" << '\n';
  return 0;
}
