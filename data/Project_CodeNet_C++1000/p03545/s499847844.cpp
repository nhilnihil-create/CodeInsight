#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> n(4);
  for (int i = 3; i >= 0; i--) {
    n.at(i) = N % 10;
    N /= 10;
  }
  for (int tmp = 0; tmp < (1 << 3); tmp++) {
    bitset<3> s(tmp);
    int t = n.at(0);
    for (int i = 0; i < 3; i++) {
      if (s.test(i)) {
        t += n.at(i + 1);
      }
      else {
        t -= n.at(i + 1);
      }
    }
    if (t == 7) {
	  cout << n.at(0);
      for (int i = 0; i < 3; i++) {
        if (s.test(i))
          cout << "+";
        else
          cout << "-";
        cout << n.at(i + 1);
      }
      cout << "=7" << endl;
      break;
    }
  }
}