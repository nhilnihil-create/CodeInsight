#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>

#define pb push_back
#define mp make_pair

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef unsigned long long ull;
typedef long long ll;

int main() {
  set<string> ss;
  int n;
  cin >> n;

  bool ok = true;
  char last = '1';
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    if (i != 0) {
      if (s.at(0) != last || ss.find(s) != ss.end()) {
        ok = false;
      }
    }
    ss.insert(s);
    last = s.at(s.size()-1);
  }

  if (ok) {
    cout << "Yes";
  } else {
    cout << "No";
  }
  cout << endl;

  return 0;
}
