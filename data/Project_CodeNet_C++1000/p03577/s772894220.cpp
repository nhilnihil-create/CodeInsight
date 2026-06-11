#include <iostream>
#include <string>
using namespace std;
 
int main() {
  string n;
  cin >> n;
  int a = n.size () - 8;
  cout << n.erase (a);
}