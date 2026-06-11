#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;

int main() {
  char b; cin >> b;
  char p;
  switch(b) {
    case 'A': p = 'T'; break;
    case 'T': p = 'A'; break;
    case 'C': p = 'G'; break;
    case 'G': p = 'C'; break;
  }
  cout << p << endl;
}
