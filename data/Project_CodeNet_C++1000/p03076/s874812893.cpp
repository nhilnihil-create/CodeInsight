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
  vi d;
  for (int i = 0; i < 5; ++i) {
    int t;
    cin >> t;
    d.pb(t);
  }

  sort(d.begin(), d.end());

  int min_res = 100000;
  do {
    int t = 0;
    for (int i = 0; i < 5; ++i) {
      t += d.at(i);
      if (i != 4) {
        if (t % 10 != 0) {
          t += (10-(d.at(i)%10));
        }
      }
    }
    min_res = min(min_res, t);
  } while (next_permutation(d.begin(), d.end()));

  cout << min_res << endl;

  return 0;
}
