#include <iostream>
#include <algorithm>

using namespace std;

int const NMAX = 100;
int v[1 + NMAX];

int main() {

  int n;
  cin >> n;
  int ans = 0;
  for(int i = 1;i <= n;i++){
    cin >> v[i];
  }
  sort(v+1, v+n+1);
  for(int i = 1;i <= n;i++){
    ans += (-1 * (i % 2)) * v[i] + ( 1 * (i % 2 == 0)) * v[i];
  }
  cout << abs(ans);
  return 0;
}
