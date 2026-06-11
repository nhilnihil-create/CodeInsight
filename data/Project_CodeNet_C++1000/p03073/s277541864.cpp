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

  int next = s.at(0)-'0';

  int count = 0;

  for (int i = 1; i < s.size(); ++i) {
    next ^= 1;
    
    if ((s.at(i)-'0') != next) {
      if (next == 1) {
        s.at(i) = '1';
      } else {
        s.at(i) = '0';
      }
      count++;
    }
  }

  cout << count << endl;
  return 0;
}
