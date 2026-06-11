#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<string> list(n);
  cin >> list.at(0);
  char a = list.at(0).back();
  for(int i=1; i<n; i++) {
    cin >> list.at(i);
    if(list.at(i).at(0) != a) {
      cout << "No" << endl;
      return 0;
    }
    a = list.at(i).back();
  }
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      if(list.at(i) == list.at(j) && i != j) {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
}