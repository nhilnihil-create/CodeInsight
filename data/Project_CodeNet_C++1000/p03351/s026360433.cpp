#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int a, b, c, d, e, f, g;
  cin >> a >> b >> c >> d;
  e=max((a-b),(b-a));
  f=max((b-c),(c-b));
  g=max((c-a),(a-c));
  if (g<=d) {
    cout << "Yes" << endl;
  }
  else {
    if (e<=d && f<=d) {
      cout << "Yes" << endl;
    }
    else {
      cout << "No" << endl;
    }
  }
}
