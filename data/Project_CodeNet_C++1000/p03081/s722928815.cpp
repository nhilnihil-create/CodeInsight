#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <climits>
#include <numeric>
#include <cmath>
#include <queue>
#include <sstream>
#include <string.h>
#include <bitset>
#include <stack>

using namespace std;
typedef long long ll;

int simulate(const string &s, const vector<pair<char, char>> &td, int pos) {
  for (auto c : td) {
    if (s[pos] != c.first) {
      continue;
    }
    if (c.second == 'L') pos--;
    else pos++;
    
    if (pos < 0) return -1;
    if (pos >= (int)s.size()) return 1;
  }
  return 0;
}

int solve(int N, const string &s, const vector<pair<char, char>> &td) {
  int low = -1, high = N;
  while(high - low > 1) {
    int mid = (low + high) / 2;
    if (simulate(s, td, mid) == -1) low = mid;
    else high = mid;
  }
  int left_fall = high;
  
  low = -1, high = N;
  while(high - low > 1) {
    int mid = (low + high) / 2;
    if (simulate(s, td, mid) == 1) high = mid;
    else low = mid;
  }
  int right_fall = N - 1 - low;
  
  return N - (left_fall + right_fall);
}

int main(){
  int N, Q;
  cin >> N >> Q;
  string s;
  cin >> s;
  vector<pair<char, char>> td(Q);
  for (int i = 0; i < Q; i++) {
    cin >> td[i].first >> td[i].second;
  }
  cout << solve(N, s, td) << endl;
  return 0;
}
