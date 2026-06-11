#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  bool fp, fw, fg, fy;
  fp = fw = fg = fy = false;

  for (int i = 0; i < N; i++) {
    string c;
    cin >> c;
    
    if (c == "P") {
      fp = true;
    } else if (c == "W") {
      fw = true;
    } else if (c == "G") {
      fg = true;
    } else {
      fy = true;
    }
  }
  
  if (fp && fw && fg && fy) {
    cout << "Four" << endl;
  } else {
    cout << "Three" << endl;
  }
}
