#include<bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  set<int> mochi;
  for(int i = 0; i < n; ++i) {
    int a; cin >> a;
    mochi.insert(a);
  }
  cout << mochi.size() << "\n";
}