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

using namespace std;
using ll = long long int;

template <class T> ostream &operator<<(ostream &os, vector<T> &v) {
  for (auto i = v.begin(); i != v.end(); i++) {
    os << *i << " ";
  }
  return os;
}


void solve(ll N){
  ll l = 0;
  ll r = N-1;
  ll c;
  string x, y, z;
  std::cout << l << std::endl;
  cin>>x;
  if(x=="Vacant")
    return;
  std::cout << r << std::endl;
  cin>>z;
  if(z=="Vacant")
    return;
  while(true){
    c=(l+r)/2;
    std::cout << c << std::endl;
    cin>>y;
    if(y=="Vacant")
      return;

    if((c-l)%2) {
      if(x==y) {
	r=c;
	z=y;
      } else {
	l=c;
	x=y;
      }
    } else {
      if(x==y) {
	l=c;
	x=y;
      } else {
	r=c;
	z=y;
      }
    }
  }
}

int main(){
  ll N;
  std::cin >> N;
  solve(N);
  return 0;
}

