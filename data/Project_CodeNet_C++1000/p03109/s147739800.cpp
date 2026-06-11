#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string s; cin>>s;
  int y = stoi(s.substr(0, 4));
  int m = stoi(s.substr(5, 2));
  if (y < 2019) cout << "Heisei" << endl;
  else if (m < 5) cout << "Heisei" << endl;
  else cout << "TBD" << endl;
}
