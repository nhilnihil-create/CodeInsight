#include<bits/stdc++.h>
using namespace std;
int main() {
  vector<int> v(3);
  for (int i = 0; i < 3; ++i) cin >>v[i];
  if (v[1] == v[2]) cout << v[0] << endl;
  if (v[0] == v[2]) cout << v[1] << endl;
  if (v[0] == v[1]) cout << v[2] << endl;
  return 0;
}