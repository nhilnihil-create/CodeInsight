#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> b(N), order;
  for (int &x: b) cin >> x;
  while(!b.empty()) {
    bool erased{};
    for (int i = b.size()-1; i >= 0; --i) {
      if (b[i] == i + 1) {
        b.erase(begin(b)+i);
        erased = 1;
        order.push_back(i+1);
        break;
      }
    }
    if (!erased) break;
  }
  if (b.size()) {
    cout << -1 << endl;
  } else {
    for_each(rbegin(order),rend(order),[](int x){cout << x << endl;});
  }
}
