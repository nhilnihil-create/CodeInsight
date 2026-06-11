#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> ns(4 + 1, 0);
  int a, b;
  for(int i = 0; i < 3; ++i) {
    cin >> a >> b;
    ns[a]++;
    ns[b]++;
  }
  for(int i = 1; i <= 4; ++i) {
    if(ns[i] >= 3) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}