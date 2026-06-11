#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> v(3);
  cin >> v[0] >> v[1] >> v[2];
  if(v[0] == v[1] && v[1] == v[2] && v[2] == v[0]) cout << "Yes" << endl;
  else cout << "No" << endl;
}