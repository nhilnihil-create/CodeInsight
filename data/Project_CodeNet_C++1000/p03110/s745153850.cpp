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
  double ans = 0;
  rep(i,n){
    double x; string s;
    cin >> x >> s;
    if(s == "JPY") ans += x;
    else ans += 380000.0 * x;
  }
  printf("%.10f\n",ans);
}
