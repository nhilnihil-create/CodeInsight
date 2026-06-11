#include <iostream>
#include <string>

using namespace std;

int const NMAX = 100;
char v[1 + NMAX][1 + NMAX];

int main() {

  int n = 0, m = 1000000000, k, inp;
  char p;
  cin >> p;
  if(p == 'A'){
    cout << 'T';
  }else if(p == 'T'){
    cout << 'A';
  }
  if(p == 'C'){
    cout << 'G';
  }else if(p == 'G'){
    cout << 'C';
  }
  return 0;
}
