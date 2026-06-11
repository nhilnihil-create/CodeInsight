#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  vector<int> v(3);
  cin >> v[0] >> v[1] >> v[2];
  sort(v.begin(), v.end());
  if(v[0] == v[1]) {
    cout << v[2] << "\n";
  } else {
    cout << v[0] << "\n";
  }
}
