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

using namespace std;
using ll = long long int;

template <class T> ostream &operator<<(ostream &os, vector<T> &v) {
  for (auto i = v.begin(); i != v.end(); i++) {
    os << *i << " ";
  }
  return os;
}


void solve(long long n, long long m, long long d){
  if(d==0)
    std::cout << setprecision(10) << (double)(m-1)/(double)n << std::endl;
  else
    std::cout << setprecision(10) << (double)(m-1)*2*(n-d)/(double)(n*n) << std::endl;
}

int main(){
  long long n;
  scanf("%lld",&n);
  long long m;
  scanf("%lld",&m);
  long long d;
  scanf("%lld",&d);
  solve(n, m, d);
  return 0;
}

