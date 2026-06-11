#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#include <cmath>
#include <stack>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long int;

template <class T> ostream &operator<<(ostream &os, vector<T> &v) {
  for (auto i = v.begin(); i != v.end(); i++) {
    os << *i << " ";
  }
  return os;
}

const long long MOD = 1000000007;

int main(){
  ll n;
  ll x = 0;
  ll y = 0;
  cin>>n;
  vector<vector<ll>> v(2,vector<ll>(n));
  rep(i,2) rep(j,n) cin>>v[i][j];
  rep(i,n) {
    if(v[0][i] < v[1][i])
      x+=(v[1][i]-v[0][i])/2;
    else
      y+=v[0][i]-v[1][i];
  }
  if(x>=y)
    std::cout << "Yes" << std::endl;
  else
    std::cout << "No" << std::endl;
  
  return 0;
}
