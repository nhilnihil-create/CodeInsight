#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;

int main() {
  int N;
  cin >> N;
  int a[N];
  int abs_max = 0;
  int point = 0;
  bool all_zero = true;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    if (a[i] != 0) {
      all_zero = false;
    }
    if (abs_max < abs(a[i])) {
      abs_max = abs(a[i]);
      point = i;
    }
  }
  if (all_zero) {
    cout << 0 << endl;
    return 0;
  } 
  vector<P> move;
  for (int i = 0; i < N; i++) {
    if (point != i) {
      a[i] += a[point];
      move.push_back(make_pair(point,i));
    }
  }
  int R = 0;
  for (int i = 0; i < N; i++) {
    R += a[i];
  }  
  if (R > 0) {
    for (int i = 1; i < N; i++) {
      move.push_back(make_pair(i-1,i));
    }
  } else {
    for (int i = N-1; i >= 1; i--) {
      move.push_back(make_pair(i,i-1));
    }
  }
  cout << (int)move.size() << endl;
  for (int i = 0; i < (int)move.size(); i++) {
    cout << move[i].F + 1 << " " << move[i].S + 1 << endl;
  }
  return 0;
}