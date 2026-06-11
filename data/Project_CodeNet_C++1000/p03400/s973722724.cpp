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
  int n,d,x;
  cin >> n >> d >> x;
  int ans = x;
  rep(i,n){
    int a;
    cin >> a;
    ans += (d-1)/a+1;
  }
  cout << ans << endl;
}
