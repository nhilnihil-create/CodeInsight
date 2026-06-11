#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {

  int n, m, ans = 1e9, bad = 0;
  int popp;
  cin >> m >> n;
  for(int i = 1;i <= n;i++){
    cin >> popp >> m;
    ans = min(ans, m);
    bad = max(bad, popp);
  }
  cout << max(0, ans - bad + 1);
  return 0;
}
