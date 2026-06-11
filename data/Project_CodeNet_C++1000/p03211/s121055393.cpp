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
  string s;
  cin >> s;

  int res = 100000;
  for (int i = 0; i < s.size()-2; ++i) {
    int si = stoi(s.substr(i, 3));
    res = min(res, abs(753-si));
  }

  cout << res << endl;
  return 0;
}
