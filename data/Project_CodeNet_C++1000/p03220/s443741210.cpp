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
  int n;
  cin >> n;

  double t, a;
  cin >> t >> a;

  double least_diff = 1000005;
  double res = -1;
  for (int i = 0; i < n; ++i) {
    double h;
    cin >> h;

    double temp = t-h*0.006;
    if (abs(temp-a) < least_diff) {
      least_diff = abs(temp-a);
      res = i+1;
    }
  }

  cout << res << endl;
  return 0;
}
