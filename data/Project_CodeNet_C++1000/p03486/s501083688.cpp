#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
  string a, b;
  cin >> a >> b;
  
  sort(a.begin(), a.end());
  sort(b.begin(), b.end(), greater<char>());
  cout << (a < b ? "Yes" : "No") << endl;  
}