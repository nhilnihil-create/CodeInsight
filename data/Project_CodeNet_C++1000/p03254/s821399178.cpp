#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>

#define pb push_back
#define mp make_pair

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef unsigned long long ull;
typedef long long ll;

int main() {
  int n, x;
  cin >> n >> x;

  ull sum = 0;
  vi c;
  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;
    c.pb(k);

    sum += k;
  }

  sort(c.begin(), c.end());

  if (sum == x) {
    cout << n << endl;
  } else if (sum < x) {
    cout << n-1 << endl;
  } else {
    int count = 0;

    for (int i = 0; i < n && x >= c.at(i); ++i) {
      x -= c.at(i);
      count++;
    }

    cout << count << endl;
  }

  return 0;
}
