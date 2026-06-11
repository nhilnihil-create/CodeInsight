#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> list(3);
  for (int i=0; i<3; i++) {
    int t;
    cin >> t;
    list.at(i) = t;
  }
  sort(list.begin(),list.end());
  int a = list.at(0)+list.at(1)+list.at(2)*10;
  cout << a << endl;
}