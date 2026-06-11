#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  bool p=false;
  bool w=false;
  bool g=false;
  bool y=false;
  bool four=false;
  for (int i=0; i < n; i++) {
    cin >> s;
    if (s=="Y")
      y=true;
    else if (s=="P")
      p=true;
    else if (s=="W")
      w=true;
    else if (s=="G")
      g=true;
  }
  if (p && w && g && y)
    cout << "Four";
  else if (p && w && g)
    cout << "Three";
}

