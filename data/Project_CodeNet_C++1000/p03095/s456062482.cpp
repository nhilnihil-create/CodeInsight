#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int N;
string S;

const long long int MOD = 1000000007;

int main() {
  cin >> N >> S;

  unordered_map<char, int> map;
  for (int i = 0; i < N; i++) {
    if (map.find(S[i]) == map.end()) {
      map[S[i]] = 1;
    } else {
      map[S[i]]++;
    }
  }

  long long int res = 1;
  for (auto it = map.begin(); it != map.end(); it++)
    res = (res * (it->second + 1)) % MOD;
  res--;
  cout << res << endl;

  return 0;
}
