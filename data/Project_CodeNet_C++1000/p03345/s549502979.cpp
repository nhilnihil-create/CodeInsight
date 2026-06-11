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
  ll a, b, c;
  ull k;
  cin >> a >> b >> c >> k;

  if (k % 2 == 0) {
    cout << a-b << endl;
  } else {
    cout << b-a << endl;
  }

  return 0;
}
