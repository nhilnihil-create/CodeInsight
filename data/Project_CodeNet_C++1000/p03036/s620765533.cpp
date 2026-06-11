#include <iostream>
using namespace std;

int r;
int D;
int x[11];

int main(){
  cin >> r >> D >> x[0];
  for(int i = 1; i <= 10; i++){
    x[i] = (x[i - 1] * r) - D;
    cout << x[i] << "\n";
  }
}