#include <iterator>
#include <list>
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <numeric>
#include <tuple>
using namespace std;

int main() {
  string S; cin >> S;
  int K; cin >> K;

  for (int i = 1; i <= S.size(); i++) {
    if (i == K || S[i-1] != '1') {
      cout << S[i-1];
      return 0;
    }
  }
  return 0;
}
