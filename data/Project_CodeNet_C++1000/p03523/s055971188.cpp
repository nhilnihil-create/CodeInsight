#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <utility>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <cstdio>
#include <cmath>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main() {
  string s;
  cin >> s;
  if (s == "KIHBR" || s == "AKIHBR" || s == "KIHABR" || s == "KIHBAR" || s == "KIHBRA" ||
      s == "AKIHABR" || s == "AKIHBAR" || s == "AKIHBRA" || s == "KIHABAR" || s == "KIHABRA" ||
      s == "KIHBARA" || s == "AKIHABAR" || s == "AKIHABRA" || s == "AKIHBARA" || s == "KIHABARA" ||
      s == "AKIHABARA")
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}