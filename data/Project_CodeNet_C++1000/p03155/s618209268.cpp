#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <list>
#include <set>
#include <stack>
#include <deque>
#include <queue>
#include <cmath>
#include <algorithm>
#include <utility>
#include <functional>
#include <fstream>
#define debug(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define repr(i,n) for(int i = (n); i > -1; i--)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const ll LINF = 1e18;
const double EPS = 1e-9;


int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n,h,w;
  cin>>n>>h>>w;
  cout << (n-h+1) * (n-w+1) << endl;

  return 0;
}
