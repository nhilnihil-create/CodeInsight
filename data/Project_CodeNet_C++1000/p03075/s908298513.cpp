#include <iostream>
#include <string>

using namespace std;

int const NMAX = 100;
char v[1 + NMAX][1 + NMAX];

int main() {

  int n = 0, m = 1000000000, k, inp;
  cin >> inp;n = max(n, inp);m = min(m, inp);
  cin >> inp;n = max(n, inp);m = min(m, inp);
  cin >> inp;n = max(n, inp);m = min(m, inp);
  cin >> inp;n = max(n, inp);m = min(m, inp);
  cin >> inp;n = max(n, inp);m = min(m, inp);
  cin >> k;
  if(n -m > k){
    cout << ":(";
  }else{
    cout << "Yay!";
  }
  return 0;
}
