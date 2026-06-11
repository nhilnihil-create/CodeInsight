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
  int n, m, x;
  cin >> n >> m >> x;

  int a[101] = {0};

  for (int i = 0; i < m; ++i) {
    int k;
    cin >> k;
    a[k]++;
  }

  int costN = 0;
  for (int i = x; i < n; ++i) {
    costN += a[i];
  }

  int cost0 = 0;
  for (int i = x; i > 0; --i) {
    cost0 += a[i];
  }

  cout << min(costN, cost0) << endl;
  return 0;
}
