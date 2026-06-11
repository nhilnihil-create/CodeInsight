#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {

  int m, ans = 0, bad = 0;
  int popp;
  string n;
  cin >> n;
  for(int i = 0;i < n.size();i++){

    popp = n[i] - '0';
    ans += (popp != (i % 2));
    bad += (popp == (i % 2));
  }
  cout << min(ans, bad);
  return 0;
}
