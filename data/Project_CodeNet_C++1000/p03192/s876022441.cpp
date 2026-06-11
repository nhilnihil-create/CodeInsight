#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  string n;
  cin >> n;

  cout << count(n.begin(), n.end(), '2');
}