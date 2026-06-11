#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  string s;
  cin >> s;
  int k;
  cin >> k;

  int n = s.length();
  map<string, int> mp;
  for (int i = 1; i <= k; i++) {
    for (int j = 0; j <= n - i; j++) {
      mp[s.substr(j, i)]++;
    }
  }
  vector<string> v;
  for (auto it = mp.begin(); it != mp.end(); it++) {
    v.push_back(it->first);
  }
  //sort(v.begin(), v.end());
  cout << v[k - 1] << endl;

  return 0;
}