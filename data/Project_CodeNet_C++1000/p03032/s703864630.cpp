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
  int n, k;
  cin>>n>>k;
  vector<int> d(n);
  rep(i,n) cin>>d[i];
  int x = min(n,k);
  int ans = 0;
  for(int i=0; i<=x; i++) {
    for(int j=0; j<=x-i; j++) {
      vector<int> v;
      int tmp = 0;
      for(int a = 0; a<i; a++) {
	v.push_back(d[a]);
	tmp+=d[a];
      }
      for(int b=0; b<j; b++) {
	v.push_back(d[n-1-b]);
	tmp+=d[n-1-b];
      }
      sort(v.begin(), v.end());
      for(int l = 0; l < k-(i+j); l++) {
	if(l >= v.size()) break;
	if(v[l] >= 0) break;
	tmp -= v[l];
      }
      ans = max(ans, tmp);
    }
  }
  std::cout << ans << std::endl;
  return 0;
}
