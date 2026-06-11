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
  map<int,int> p;
  rep(i,n){
    int x = i+1;
    for(int m = 2; m*m<=x; ++m){
      while(x%m==0){
        p[m]++;
        x /= m;
      }
    }
    if(x>1) p[x]++;
  }
  auto f = [&](int n){
    --n;
    int res = 0;
    for(auto i:p){
      if(i.second<n)break;
      ++res;
    } 
    return res;
  };
  int ans = f(75)
          + f(25)*(f(3)-1)
          + f(15)*(f(5)-1)
          + f(5)*(f(5)-1)/2*(f(3)-2);
  cout << ans << endl;
}