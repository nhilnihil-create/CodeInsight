#include <bits/stdc++.h>
using namespace std;

int main() {
 int R;
 cin >> R;
  if(R < 1200) cout << "ABC" << endl;
  if(R >= 1200 && R < 2800) cout << "ARC" << endl;
  if(R >= 2800) cout << "AGC" << endl;
  return 0;
}