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
  map<string,int> mp;
  
  int n;
  int m;
  cin >> n;
  
  int res = 0;
  while (n--) {
    string s;
    cin >> s;
    mp[s]++;
  }
  
  cin >> m;
  
  while (m--) {
    string s;
    cin >> s;
    mp[s]--;
  }
  
  for (const auto &p: mp) {
    res = max(res, p.second);
  }
  
  cout << res << endl;
  
  return 0;
}