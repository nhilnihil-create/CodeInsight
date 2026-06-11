#include <iostream>
#include <string>
using namespace std;
 
int main() {
  string s;
  cin >> s;
  if (s == "xxx")
    cout << "700";
  else if (s == "oxx")
    cout << "800";
  else if (s == "xox")
    cout << "800";
  else if (s == "xxo")
    cout << "800";
  else if (s == "oox")
    cout << "900";
  else if (s == "oxo")
    cout << "900";
  else if (s == "xoo")
    cout << "900";
  else if (s == "ooo")
    cout << "1000";
}