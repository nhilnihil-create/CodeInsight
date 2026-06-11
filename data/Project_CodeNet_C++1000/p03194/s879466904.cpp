#include <algorithm>
#include <iostream>
#include <map>
#include <string>

using namespace std;

void check(map<long long, long long> mp) {
  cout << "-----------------------------" << endl;
  for (auto it = mp.begin(); it != mp.end(); it++) {
    cout << it->first << "," << it->second << endl;
  }
}

int main() {
  long long n, p;
  cin >> n >> p;

  map<long long, long long> res;
  long long num = 0;
  long long tmp = p;
  if (p == 1) {
    res[1] = 1;
    num++;
  }
  for (long long i = 2; i * i <= p; i++) {
    while (tmp % i == 0) {
      res[i]++;
      num++;
      tmp /= i;
    }
  }
  if (tmp != 1) {
    res[tmp] = 1;
    num++;
  }
  long long ans = 1;
  for (auto it = res.begin(); it != res.end(); it++) {
    for (int i = 0; i < it->second / n; i++) {
      ans *= it->first;
    }
  }
  cout << ans << endl;
  return 0;
}