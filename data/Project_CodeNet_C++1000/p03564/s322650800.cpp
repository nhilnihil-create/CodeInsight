#include <iostream>
#include <algorithm>

using namespace std;

int const nmax = 100;
int v[1 + nmax];

int main() {

  int n, k, p = 1;
  cin >> n >> k;
  for(int i = 1;i <= n;i++){
    p = min(p * 2, p + k);
  }
  cout << p;
  return 0;
}
