#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int s;
  cin >> s;
  vector<int> a;
  int x = s;
  int cnt = 1;
  while(true) {
    a.push_back(x);
    rep(i, a.size()-1) {
      if (a.at(i) == x) {
        cout << cnt << endl;
        return 0;
      }
    }
    if (x%2 == 0) x /= 2;
    else x = 3*x + 1;
    cnt++;
  }
}