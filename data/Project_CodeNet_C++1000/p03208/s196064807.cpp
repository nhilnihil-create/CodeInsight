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
  int n, k;
  cin >> n >> k;
  vi trees;

  while (n--) {
    int h;
    cin >> h;
    trees.pb(h);
  }
  
  sort(trees.begin(), trees.end());

  int res = 1000000001;
  for (int i = 0; i+k-1 < trees.size(); ++i) {
    res = min(res, trees.at(i+k-1)-trees.at(i));
  }

  cout << res << endl;
  return 0;
}
