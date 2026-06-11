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


void solve(long long N, std::vector<long long> P){
  vector<ll> v(N+1);
  for(ll i=0; i<N; i++) {
    v[P[i]] = i;
  }
  ll ans = 0;
  ll cnt = 0;
  ll prev = -1;
  for(ll i=1; i<N+1; i++) {
    if(v[i]>prev) cnt++;
    else {
      ans = max(ans, cnt);
      cnt = 1;
    }
    prev = v[i];
  }
  ans = max(ans, cnt);
  std::cout << N-ans << std::endl;
}

int main(){
  long long N;
  scanf("%lld",&N);
  std::vector<long long> P(N);
  for(int i = 0 ; i < N ; i++){
    scanf("%lld",&P[i]);
  }
  solve(N, std::move(P));
  return 0;
}

