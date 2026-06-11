#include <bits/stdc++.h>
using namespace std;

int main () {
  int d;
  cin >> d;

  cout << "Christmas";
  if (25-d>=1) cout << " " << "Eve";
  if (25-d>=2) cout << " " << "Eve";
  if (25-d==3) cout << " " << "Eve";
  cout << endl;

  return 0;
}
