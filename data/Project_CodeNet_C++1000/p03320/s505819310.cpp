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
#define int long long
int dsum(long long n) {
  int s = 0;
  while (n) s += n%10, n/=10;
  return s;
}

long long f(int S, long long X) {
  for (int n=0; n<=15; n++) {
    long long rest = X;
    rep(_, n) rest /= 10;
    if (rest%10 == 9) continue;
    rest++;
    int nokori = 9-(rest%10);
    rep(_, n) rest *= 10;
    int s = S - dsum(rest);
    if (s < 0) continue;
    long long r = 1;
    rep(_, n) {
      int g = min(s, 9LL);
      rest += r*g;
      s -= g;
      r *= 10;
    }
    if (s > nokori) continue;
    rest += r*s;
    //cout<<"f("<<S<<","<<X<<")="<<rest<<"\n";
    return rest;
  }
  //cout<<"f("<<S<<","<<X<<")=inf\n";
  return 1e16;
}

int K;
signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> K;
  long long cur = 0;
  rep(_, K) {
    pair<double, long long> m = make_pair(1e16, -1);
    for (int s=1; s<=150; s++) {
      long long cand = f(s, cur);
      m = min(m, make_pair((double)cand/(double)s, cand));
    }
    cur = m._2;
    cout << cur << "\n";
  }
  return 0;
}
