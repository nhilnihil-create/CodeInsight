#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

int main() {
  int N, ans{};
  cin >> N;
  map<int,int> m;
  while(cin >> N) ++m[N];
  for (auto &p:m) ans += p.second - (p.first <= p.second) * p.first;
  cout << ans << endl;
}
