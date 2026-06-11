#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define MOD_NUMBER 1000000007

template <class T> void vector_print(vector<T> vec) {
  for (unsigned int i = 0; i < vec.size(); i++) {
    cout << vec.at(i);
    if (i < vec.size()-1) {
      cout << " ";
    } else if (i == vec.size()-1) {
      cout << endl;
    }
  }
}

int main() {
  ll x1, x2, x3, x4, y1, y2, y3, y4;
  cin >> x1 >> y1 >> x2 >> y2;

  x3 = x2-(y2-y1);
  y3 = y2-(x1-x2);
  x4 = x3-(y3-y2);
  y4 = y3-(x2-x3);

  cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
  return 0;
}
