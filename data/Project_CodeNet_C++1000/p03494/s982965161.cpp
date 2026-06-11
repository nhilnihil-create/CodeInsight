#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {

  int n, a, b, ab = 1e9, polpo;
  cin >> n;
  for(int i = 1;i <= n;i++){
    cin >> a;
    b = 0;
    while(a % 2 == 0){
      a /= 2;
      b++;
    }
    ab = min(ab, b);
  }
  cout << ab;
  return 0;
}
