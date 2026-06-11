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
  int n;
  cin >> n;
  vector<int> l(n);
  rep(i,n) cin >> l[i];
  sort(l.begin(),l.end());
  int s = 0;
  rep(i,n-1) s+= l[i];
  cout << (s>l[n-1]?"Yes":"No") << endl;
}
