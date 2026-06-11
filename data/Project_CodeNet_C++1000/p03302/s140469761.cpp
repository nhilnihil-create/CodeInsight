#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
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

  int a, b; cin >> a >> b;
  if (a + b == 15) cout << "+\n";
  else if (a * b == 15) cout << "*\n";
  else cout << "x\n";
  return 0;
}
