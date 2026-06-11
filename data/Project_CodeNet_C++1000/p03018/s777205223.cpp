#include <iostream>
#include <iomanip>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <stack>
#include <utility>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;
typedef long long int lld;
typedef pair<int, int> pii;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  int BCs = 0;
  lld ans = 0;
  string cad = "";
  for (int i = s.size()-1; i >= 0; --i) {
    if (s[i] == 'A') {
      if (cad != "") {
        BCs = 0;
        cad = "";
      } 
      ans += BCs;
    } else cad += s[i];
    if (cad == "B") {
      BCs = 0;
      cad = "";
    }
    if (cad == "CB") {
      BCs++;
      cad = "";
    } else if (cad.size() == 2) {
      BCs = 0;
      cad.pop_back();
    }
  }
  cout << ans << "\n";
  return 0;
}