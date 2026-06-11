#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int main() {
  int n;
  cin >> n;
  if (n == 3) {
    cout << "2 5 63" << endl;
    return 0;
  }
  int m = n/8;
  vector<int> ans;
  int a = n%8;
  if (a % 2 == 1) {
    ans.push_back(m*12+6);
  }
  if (a >= 2) {
    ans.push_back(m*12+2);
    ans.push_back(m*12+4);
  }
  if (a >= 4) {
    ans.push_back(m*12+3);
    ans.push_back(m*12+9);
  }
  if (a >= 6) {
    ans.push_back(m*12+8);
    ans.push_back(m*12+10);
  }

  for (int i = 0; i < m; ++i) {
    ans.push_back(i*12+2);
    ans.push_back(i*12+3);
    ans.push_back(i*12+4);
    ans.push_back(i*12+6);
    ans.push_back(i*12+8);
    ans.push_back(i*12+9);
    ans.push_back(i*12+10);
    ans.push_back(i*12+12);
  }
  for (int i : ans) {
    cout << i << " ";
  }
  cout << endl;
}
