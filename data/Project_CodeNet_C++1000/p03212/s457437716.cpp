#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool is753(int i) {
  bool has7{}, has5{}, has3{};
  while (i) {
    switch (i % 10) {
      case 7:
        has7 = true;
        break;
      case 5:
        has5 = true;
        break;
      case 3:
        has3 = true;
        break;
      default:
        return false;
    }
    i /= 10;
  }
  return has7 && has5 && has3;
}

int main() {
  int N, ans{};
  cin >> N;

  vector<long long> V{3, 5, 7};
  for (int i = 0;;++i) {
    auto next = V[i]*10;
    if (next > N) break;
    V.push_back(V[i]*10+3);
    V.push_back(V[i]*10+5);
    V.push_back(V[i]*10+7);
  }

  ans = count_if(begin(V), upper_bound(begin(V),end(V),N),
           [&](int x) { return is753(x); });
  cout << ans << endl;
}
