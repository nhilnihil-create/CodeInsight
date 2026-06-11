#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define MOD 1000000007
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef pair<int, int> P;
typedef pair<long long, long long> LLP;

int main() {

  int A, B, C;
  cin >> A >> B >> C;
  if (A == B) cout << C << endl;
  else if (A == C) cout << B << endl;
  else cout << A << endl;
    
  return 0;
}