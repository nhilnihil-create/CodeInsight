#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> list(4);
  for (int i=0; i<3; i++) {
    int t;
    cin >> t;
    list.at(i) = t;
  }
  sort(list.begin(),list.end());
  int a=0;
  for (int i=1; i<=2; i++) {
    a += list.at(i+1)-list.at(i);
  }
  cout << a << endl;
}