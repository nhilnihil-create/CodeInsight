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
  int idx;
  rep(i,n){
    int a;
    cin >> a;
    if(a==1) idx = i+1;
  }
  
  --k;
  int ans = (idx-1+k-1)/k;
  idx = ans*k+1;
  ans += (n-idx+k-1)/k;
  cout << ans << endl;
}
