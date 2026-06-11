#include <bits/stdc++.h>
using namespace std;

int main(){
  string x;
  cin >> x;
  if (x[3] == x[2] && x[2] == x[1])
    cout << "Yes" << endl;
  else if (x[2] == x[1] && x[1] == x[0])
    cout << "Yes"<< endl;
  else
    cout << "No" << endl;
}