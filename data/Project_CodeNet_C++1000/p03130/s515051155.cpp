#include <iostream>
#include <vector>

using namespace std;
int main() {
  int a;
  vector<int> r(4);
  bool cond = true;
  while (cin >> a) {
    ++r[a-1];
    if(r[a-1]>2) cond = false;
  }
  cout << (cond ? "YES" : "NO") << endl;
  return 0;
}
