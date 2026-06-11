#include <bits/stdc++.h>
using namespace std;

int main() {
  int Q;
  cin >> Q;
  vector<int> Like;
  set<int> s;
  for (int i = 3; i < 100000; i += 2) {
    int q = sqrt(i);
    bool b = false;
    for (int j = 2; j <= q; j++) {
      if (i%j == 0) {
        b = true;
        break;
      }
    }
    if (!b) s.insert(i);
  }
  Like.push_back(3);
  for (int i = 5; i < 1000000; i += 2) {
    if (s.count(i) && s.count((i+1)/2)) Like.push_back(i); 
  }
  for (int i = 0; i < Q; i++) {
    int l, r;
    cin >> l >> r;
    auto itr1 = lower_bound(Like.begin(), Like.end(), l);
    auto itr2 = lower_bound(Like.begin(), Like.end(), r+1);
    cout << distance(itr1, itr2) << endl;
  }
}