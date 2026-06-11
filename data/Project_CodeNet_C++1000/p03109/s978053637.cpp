#include <iostream>
#include <string>

using namespace std;

int main() {
  string str;
  cin >> str;
  for (auto itr = str.begin(); itr != str.end();) {
    if (*itr == '/')
      itr = str.erase(itr);
    else
      ++itr;
  }
  if (stoi(str) <= 20190430)
    cout << "Heisei" << endl;
  else
    cout << "TBD" << endl;
}