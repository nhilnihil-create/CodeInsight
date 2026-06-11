#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <cctype>

#define pb push_back
#define mp make_pair

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef unsigned long long ull;
typedef long long ll;

int main() {
  string s;
  cin >> s;

  char init = s.at(0);
  int occ = 0;
  for (int i = 2; i < s.size()-1; ++i) {
    if (s.at(i) == 'C') {
      occ++;
    }
  }

  int lowocc = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (islower(s.at(i))) {
      lowocc++;
    }
  }

  if (init == 'A' && occ == 1 && lowocc == s.size()-2) {
    cout << "AC" << endl;
  } else {
    cout << "WA" << endl;
  }

  return 0;
}
