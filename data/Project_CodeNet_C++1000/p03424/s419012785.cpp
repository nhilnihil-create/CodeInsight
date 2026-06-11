#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

ifstream in("bleach.in");
ofstream out("bleach.out");

int const NMAX = 1e6;
int v[1 + NMAX];

int main() {

  int badn, bada = 3;
  char badc;
  cin >> badn;
  for(int i =1;i <= badn;i++){
    cin >> badc;
    if(badc == 'Y'){
      cout << "Four";
      return 0;
    }
  }
  if(bada == 3){
    cout << "Three";//freeze
  }
  return 0;
}
