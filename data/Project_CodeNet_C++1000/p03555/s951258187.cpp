#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<string> vec(2);

  cin >> vec[0] >> vec[1];

  if (vec[0][0] == vec[1][2] && vec[0][1] == vec[1][1] &&
      vec[0][2] == vec[1][0]) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
