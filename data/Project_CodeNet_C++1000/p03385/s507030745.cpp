#include <bits/stdc++.h>
using namespace std;


int main() {
  string text;
  
  cin >> text;
  
  if(text.at(0) == 'a' && text.at(1) == 'b' && text.at(2) == 'c')
    cout << "Yes";
  
  else if(text.at(0) == 'a' && text.at(1) == 'c' && text.at(2) == 'b')
    cout << "Yes";

  else if(text.at(0) == 'b' && text.at(1) == 'a' && text.at(2) == 'c')
    cout << "Yes";
  
  else if(text.at(0) == 'b' && text.at(1) == 'c' && text.at(2) == 'a')
    cout << "Yes";
  
  else if(text.at(0) == 'c' && text.at(1) == 'b' && text.at(2) == 'a')
    cout << "Yes";

  else if(text.at(0) == 'c' && text.at(1) == 'a' && text.at(2) == 'b')
    cout << "Yes";

  else 
    cout << "No";

  
}
