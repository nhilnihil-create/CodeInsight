#include <iostream>
#include <string>

using namespace std;

int const NMAX = 1e5;
int v[1 + NMAX];

int main() {

  int n, pos = 1, p, ans = 1;
  string GUIDO;
  cin >> n >> p >> ans;
  for(int i =1;i <= 10;i++){
    ans = n * ans - p;
    cout << ans << '\n';
  }
  return 0;
}
