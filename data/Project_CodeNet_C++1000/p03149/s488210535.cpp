#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  string n="";

  for (int i=0; i<4; i++) {
    string t;
    cin >> t;

    n+=t;
  }

  sort(n.begin(), n.end());

  cout << (n=="1479" ? "YES": "NO") << endl;
}