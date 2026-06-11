#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> vec(n);
  for (int i = 0; i < n; i++) {
    cin >> vec.at(i);
  }
  sort(vec.begin(),vec.end());
  int r = 0;
  int bef = 0;
  int tmp = 0;
  for (int i = 0; i < n; i++) {
    tmp = vec.at(i);
    if (tmp != bef) {
      r += 1;
    }
    bef = tmp;
  }
  cout << r << endl;
}