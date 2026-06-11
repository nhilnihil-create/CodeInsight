#include <bits/stdc++.h>
using namespace std;

int main() { string d;
  cin >> d;
  if(d.at(0)==d.at(1) && d.at(1)==d.at(2)){
    cout << "Yes" << endl;
  }
  else if (d.at(1)==d.at(2) && d.at(2)==d.at(3)){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}