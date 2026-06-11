#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int n, q;
  string str;
  cin >> n >> q >> str;
  vector<int> vec(n, 0);
  for (int i = 1; i < n; ++i)
    vec[i] = vec[i-1] + (str[i-1] == 'A' && str[i] == 'C');
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << vec[r-1] - vec[l-1] << endl;
  }
}