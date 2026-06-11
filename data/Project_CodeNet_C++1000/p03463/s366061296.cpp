#include <iostream>
#include <algorithm>

using namespace std;

int const NMAX = 100;
int v[1 + NMAX + 1];

int main() {

  int n, a, b;
  cin >> n >> a >> b;
  //if(n == 2){
  //  cout << "Draw";
  //}
  if(abs(a - b) % 2 == 0){//First wins
    cout << "Alice";
  }else{
    cout << "Borys";
  }
  return 0;
}
