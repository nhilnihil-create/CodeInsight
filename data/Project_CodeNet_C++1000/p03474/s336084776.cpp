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
  int a, b;
  cin >> a >> b;

  string s;
  cin >> s;

  bool ok = true;

  for (int i = 0; i < a+b+1 && ok; ++i) {
    if (i != a) {
      if (s.at(i) == '-') {
        ok = false;
      }
    } else {
      if (s.at(i) != '-') {
        ok = false;
      }
    }
  }

  if (ok) {
    cout << "Yes";
  } else {
    cout << "No";
  }
  cout << endl;
  return 0;
}
