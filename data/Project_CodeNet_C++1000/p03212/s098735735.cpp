#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <iomanip>
#include <set>
using namespace std;
typedef long long ll;

ll N, ans;

void dfs(ll num, int three, int five, int seven) {
  if (num > N) {
    return;
  }
  if (three * five * seven > 0) {
    ans++;
  }

  dfs(10 * num + 3, 1, five, seven);
  dfs(10 * num + 5, three, 1, seven);
  dfs(10 * num + 7, three, five, 1);

  return;
}

int main() {
  cin >> N;
  dfs(0, 0, 0, 0);
  cout << ans << endl;
}