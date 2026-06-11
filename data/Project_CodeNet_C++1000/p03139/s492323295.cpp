#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <numeric>
#include <complex>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef vector<int> vint;
typedef pair<int, int> pint;
typedef vector<long long> vlong;
#define vpush(a,x) a.push_back(x);
#define rep(i, n) REP(i, 0, n)
#define all(v) v.begin(), v.end()
#define REP(i, x, n) for(int i = x; i < n; i++)
#define INF 2e9
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n,a,b;
  cin>>n>>a>>b;
  cout<<min(a,b)<<' ';
  cout<<(0<=(a+b)-n ? (a+b)-n : 0)<<'\n';
  return(0);
}
