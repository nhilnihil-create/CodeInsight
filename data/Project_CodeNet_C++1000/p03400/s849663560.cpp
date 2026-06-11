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
  int n, d, x;
  cin >> n >> d >> x;

  int count = 0;
  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;

    int mult = 0;
    while (1+mult*k <= d) {
      count++;
      mult++;
    }
  }

  cout << count+x << endl;
  return 0;
}
