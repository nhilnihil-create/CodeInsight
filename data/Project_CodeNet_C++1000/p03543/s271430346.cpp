#include <bits/stdc++.h>
using namespace std;


int main() {
  string N;
  cin >> N;
  
  int fst=0, scd=0;
  for (int i=0; i<4; i++) {
    if (N.at(0)==N.at(i)) fst++;
    else if (N.at(1)==N.at(i)) scd++;
    //else if (N.at(2)==N.at(i)) thd++;
    //else if (N.at(3)==N.at(i)) fth++;
  }
  
  if (N.at(0)==N.at(1) && N.at(0)==N.at(2)) cout << "Yes" << endl;
  else if (N.at(1)==N.at(2) && N.at(1)==N.at(3)) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
