#include <bits/stdc++.h>
using namespace std;
int main() {
  int N,d;
  set<int> mochi;
  for (cin >> N; N; N--) {
    cin >> d;
    mochi.insert(d);
  }
  cout << mochi.size();
}