#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
#include <cassert>
#define rep(i,n) for(int i = 0; i < n; ++i )
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  map<char,char> ans = {
    {'A','T'},
    {'T','A'},
    {'C','G'},
    {'G','C'},
  };
  char c;
  cin >> c;
  cout << ans[c] << endl;
}
