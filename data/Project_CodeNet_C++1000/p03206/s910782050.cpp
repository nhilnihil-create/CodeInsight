#include <bits/stdc++.h>
using namespace std;

int main() {
  int d;
  cin >> d;
  int tmp = d % 10;
  if (tmp == 2) cout << "Christmas Eve Eve Eve" << endl;
  else if (tmp == 3) cout << "Christmas Eve Eve" << endl;
  else if (tmp == 4) cout << "Christmas Eve" << endl;
  else cout << "Christmas" << endl;
}
