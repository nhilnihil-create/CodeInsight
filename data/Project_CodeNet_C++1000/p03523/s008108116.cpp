#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;

int main() {
  string s;
  cin >> s;
  string target = "AKIHABARA";
  if (s.length() > target.length()) {
    cout << "NO" << endl;
    return 0;
  }
  if (s == target) {
    cout << "YES" << endl;
    return 0;
  }
  if (s.length() == target.length() && s != target) {
    cout << "NO" << endl;
    return 0;
  }
  set<string> str_set = {"KIHBR",    "AKIHBR",  "KIHABR",  "KIHBAR",
                         "KIHBRA",   "AKIHABR", "AKIHBAR", "AKIHBRA",
                         "KIHABAR",  "KIHABRA", "KIHBARA", "AKIHABAR",
                         "AKIHABRA", "KIHABARA"};
  if (str_set.find(s) != str_set.end())
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}