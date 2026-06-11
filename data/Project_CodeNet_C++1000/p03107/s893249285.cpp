#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <stack>

#define pb push_back
#define mp make_pair

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef unsigned long long ull;
typedef long long ll;

int main() {
  stack<char> sc;
  
  string s;
  cin >> s;
  
  int count = 0;
  
  for (char c : s) {
    if (sc.empty()) {
      sc.push(c);
    } else {
      if (c == sc.top()) {
        sc.push(c);
      } else {
        sc.pop();
        count += 2;
      }
    }
  }
  
  cout << count << endl;
  return 0;
}