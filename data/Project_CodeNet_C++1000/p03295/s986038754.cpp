#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  
  vector<pair<int, int>> req(M);
  for (int m = 0; m < M; ++m) {
    int a, b;
    cin >> a >> b;
    req[m] = {a, b};
  }
  sort(req.begin(), req.end(), 
       [](const pair<int, int>& lhs, const pair<int, int>& rhs) {
         if (lhs.second != rhs.second) {
           return lhs.second < rhs.second;
         }
         return lhs.first < rhs.first;
       });
  int pre = -1;
  int result = 0;
  for (const pair<int, int>& p : req) {
    if (p.first <= pre && pre < p.second) {
      continue;
    }
    pre = p.second - 1;
    ++result;
  }
  cout << result << endl;
  
  return 0;
}
