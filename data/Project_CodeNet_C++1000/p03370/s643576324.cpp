#include <iostream>
#include <algorithm>

using namespace std;

int const nmax = 100;
int v[1 + nmax];

int main() {

  int n, m, sum = 0, p, mint = 1000000;
  cin >> n >> m;
  for(int i = 1;i <= n;i++){
    cin >> p;
    sum += p;
    mint = min(p, mint);
  }
  //cerr << m - sum;
  cout << n + (m -sum) / mint;
  return 0;
}
