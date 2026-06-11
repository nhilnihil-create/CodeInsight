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
  int n,k;
  cin >> n >> k;
  ll ans = 0;
  for(ll b=k+1;b<=n;++b){
    ans += n/b*(b-k);
    ans += max(n%b-k+1,0LL);
  }
  if(k==0) ans-=n;
  cout << ans << endl;
}