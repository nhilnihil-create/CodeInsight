#include <bits/stdc++.h>
using namespace std;

int main() {
  string N;
  cin >> N;
  char a=N.at(0),b=N.at(1),c=N.at(2),d=N.at(3);
  if ((a == b && b == c && c == a)||(b == c && c == d && d == b)){
  cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
 }
