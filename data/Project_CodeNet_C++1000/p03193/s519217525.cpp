#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <string>
#include <stack>
#include <regex>
#include <numeric>
#include <queue>
 
#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(v) (v).begin(), (v).end()
 
using namespace std;
 
typedef long long ll;

int main(int argc, char const *argv[])
{
  ll n,h,w;
  cin >> n>> h>>w;
  ll res = 0;
  REP(i,n){
    ll a,b;
    cin >> a >> b;
    if (a >= h && b >= w) res++;
  }
  cout << res << endl;
  return 0;
}
