#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>
#include <cassert>
#include <bitset>
using namespace std;

#define int long long
typedef pair<int, int> P;
#define rep(i, n) for (int i=0; i<(n); i++)
#define all(c) (c).begin(), (c).end()
#define uniq(c) c.erase(unique(all(c)), (c).end())
#define index(xs, x) (int)(lower_bound(all(xs), x) - xs.begin())
#define _1 first
#define _2 second
#define pb push_back
#define INF 1145141919
#define MOD 1000000007

int Q;
int g(int x, int A, int B) {
  //xy<AB
  int y = (A*B+x-1)/x-1;
  return y - (y>=B);
}
int f(int x, int A, int B) {
  int num = A*B-x+1 - (x <= A);
  return A*B-1-(num-g(x, A, B));
}
int solve(int A, int B) {
  //for (int x=1; x<=A*B; x++) cout<<f(x,A,B)<<",";cout<<"\n";
  long long lo = 1, hi = A*B;
  while (hi-lo>=30000) {
    long long a = (0LL+lo+lo+hi)/3,
              b = (0LL+lo+hi+hi)/3;
    if (f(a, A, B) <= f(b, A, B)) hi = b;
    else lo = a;
  }
  int m = A*B-1;
  for (int i=max(1LL, lo-30000); i<=min(A*B, hi+30000); i++) m = min(m, f(i, A, B));
  return m;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> Q;
  rep(i, Q) {
    long long a, b;
    cin >> a >> b;
    long long m = solve(a, b);
    m = min(m, solve(b, a));
    cout << m << "\n";
  }
  return 0;
}
