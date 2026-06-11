#include <bits/stdc++.h>
using namespace std;

int main() {
  int D, G;
  cin >> D >> G;
  vector<int> p(D), c(D);
  for (int i = 0; i < D; i++) 
    cin >> p.at(i) >> c.at(i);
  int min = 0;
  for (int i = 0; i < D; i++) {
    min += p.at(i);
  }
  for (int tmp = 0; tmp < (1 << D); tmp++) {
    bitset<10> s(tmp);
    int count = 0, point = 0;
    for (int i = 0; i < D; i++) {
      if (s.test(i)) {
        count += p.at(i);
        point += p.at(i) * (i + 1) * 100 + c.at(i);
      }
    }
    if (point >= G) {
      if (min > count) {
        min = count;
      }
    }
    else {
      int n;
      for (int i = D - 1; i >= 0; i--) {
        if (!s.test(i)) {
          n = i;
          break;
        }
      }
	  for (int i = 0; i < p.at(n); i++) {
        point += (n + 1) * 100;
        count++;
        if (point >= G) {
          if (min > count)
            min = count;
          break;
        }
      }
    }
  }
  cout << min << endl;
}