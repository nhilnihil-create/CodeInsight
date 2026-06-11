#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <iomanip>
#include <queue>
#include <map>
#include <set>
#include <random>
#include <sstream>
#include <stack>
#include <deque>

using namespace std;

#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

string S;

int main() {
  cin >> S;
  int n = S.size();
  int c[3] = {};
  rep(i,n) c[S[i]-'a']++;
  sort(c, c+3);
  if (c[2] - c[0] <= 1) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
