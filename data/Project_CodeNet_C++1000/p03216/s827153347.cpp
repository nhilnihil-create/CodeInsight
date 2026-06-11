#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <cassert>
#include <cstring>
#include <chrono>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

struct TStorage {
  int numZeroes = 0;
  int numOnes = 0;
  ll value = 0;

  void Add(char c) {
    if (c != 'M' && c != 'C') return;
    if (c == 'M') {
      numZeroes++;
    } else {
      numOnes++;
      value += numZeroes;
    }
  }
  void Remove(char c) {
    if (c != 'M' && c != 'C') return;
    if (c == 'M') {
      numZeroes--;
      value -= numOnes;
    } else {
      numOnes--;
    }
  }

  ll GetValue() {
    return value;
  }
};

ll Solve(const string& s, int k) {
  ll result = 0;
  TStorage storage;
  for (int i = 0; i < k; ++i) storage.Add(s[i]);
  int l = 0;
  int r = k - 1;
  while (l < s.size()) {
    if (s[l] == 'D') {
      result += storage.GetValue();
    }

    storage.Remove(s[l]);
    l++;
    r++;
    if (r < s.size()) storage.Add(s[r]);
  }
  return result;
};

int main()
{
  int n;
  cin >> n;
  string s;
  cin >> s;
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int k;
    cin >> k;
    cout << Solve(s, k) << endl;
  }
  return 0;
}
