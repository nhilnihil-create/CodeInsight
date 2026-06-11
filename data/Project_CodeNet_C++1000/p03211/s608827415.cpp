#include <bits/stdc++.h>
using namespace std;
int main() {
  string s,t;
  cin >> s;
  int x;
  int size = s.size()-2;
  vector<int> list(size);
  for(int i=0; i<size; i++) {
    t = s.substr(i,3);
    x = atoi(t.c_str());
    x = abs(753-x);
    list.at(i) = x;
  }
  sort(list.begin(),list.end());
  cout << list.at(0) << endl;
}