#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for(int i=0;(i)<(int)(n);(i)++)

int N, Q;
string table;
vector<pair<char, char>> qs;

bool check(int x) {
  int now = x;
  REP(i,Q) if (qs[i].first == table[now]) {
    char dir = qs[i].second;
    if (dir == 'L') {
      now--;
      if (now < 0) return true;
    } else {
      now++;
      if (N <= now) return false;
    }
  }
  return false;
}

// (lb, ub]
int search() {
  int low = -1, high = N;
  while (high - low > 1) {
    int mid = (high + low) / 2;
    if (check(mid)) low = mid; else high = mid;
  }
  return high;
}

bool rcheck(int x) {
  int now = x;
  REP(i,Q) if (qs[i].first == table[now]) {
    char dir = qs[i].second;
    if (dir == 'L') {
      now--;
      if (now < 0) return false;
    } else {
      now++;
      if (N <= now) return true;
    }
  }
  return false;
}

// (lb, ub]
int rsearch() {
  int low = -1, high = N;
  while (high - low > 1) {
    int mid = (high + low) / 2;
    if (rcheck(mid)) high = mid; else low = mid;
  }
  return high;
}

int main() {
  cin >> N >> Q;
  cin >> table;

  qs.resize(Q);
  REP(i,Q) cin >> qs[i].first >> qs[i].second;

  int l = search();
  int r = rsearch();
  cout << N - (l + 1 + (N - 1 - r)) << endl;

  return 0;
}
