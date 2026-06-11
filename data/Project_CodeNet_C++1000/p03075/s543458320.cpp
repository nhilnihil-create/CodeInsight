#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> vec(5);
  for (auto &v : vec)
    cin >> v;
  int k;
  cin >> k;
  bool flag = true;
  for (auto &v1 : vec)
    for (auto &v2 : vec)
      if (k < abs(v1 - v2))
        flag = false;
  cout << (flag ? "Yay!" : ":(") << endl;
}