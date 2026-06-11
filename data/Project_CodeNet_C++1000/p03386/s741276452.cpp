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
  //bruteforce is ok

  int a, b, k;
  cin >> a >> b >> k;

  for (int i = a; i <= b; ++i) {
    if (i <= a+k-1 || i >= b-k+1) {
      cout << i << endl;
    }
  }

  return 0;
}
