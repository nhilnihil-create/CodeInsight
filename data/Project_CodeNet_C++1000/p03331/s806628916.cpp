#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric>
#include <set>
#include <cstdlib>
#include <queue>
#include <map>

using namespace std;

typedef long long llint;
typedef long double ld;
#define inf 1e18
#define mod 1000000007
priority_queue<llint,vector<llint>,greater<llint>> que;
//priority_queue<llint> q;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

llint n,a,b;

void solve(){
  cin >> n;
  int ans=0;
  while(n>10){
    ans+=n%10;
    n/=10;
  }
  ans+=n;
  cout << ans << endl;
}

int main(int argc, char *argv[]) {
  solve();
  return 0;
}
