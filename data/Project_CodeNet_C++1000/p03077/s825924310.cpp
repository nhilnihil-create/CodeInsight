#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
  ll n;
  cin >> n;
  vector<ll> vec(5);
  for (auto &v : vec)
    cin >> v;
  ll s = *min_element(vec.begin(), vec.end());
  cout << 4 + (n + (s - 1)) / s << endl;
}