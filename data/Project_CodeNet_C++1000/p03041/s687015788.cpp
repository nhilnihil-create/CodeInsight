#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<char> vec(n);
  for (auto &v : vec)
    cin >> v;
  vec[k-1] = vec[k-1] + 'a' - 'A';

  for (auto &v : vec)
    cout << v;
  cout << endl;
}