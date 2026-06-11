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


void solve(long long N, std::vector<long long> a, std::vector<long long> b, std::vector<long long> c){
  sort(c.rbegin(), c.rend());
  vector<ll> ans(N);
  map<ll, vector<ll>> m;
  for(ll i=0; i<N-1; i++) {
    m[a[i]].push_back(b[i]);
    m[b[i]].push_back(a[i]);
  }
  ll r = -1;
  ll e = -1;
  for(auto x : m) {
    // std::cout << x.second.size() << std::endl;
    // std::cout << e << std::endl;
    ll size = x.second.size();
    if(e < size) {
      e = size;
      r = x.first;
    }
  }
  auto it = c.begin();
  ans[r-1] = *(it++);
  queue<ll> q;
  q.push(r);
  set<ll> s;
  while(!q.empty()) {
    ll x = q.front();
    q.pop();
    s.insert(x);
    for(auto y : m[x]) {
      if(s.find(y) != s.end()) continue;
      q.push(y);
      ans[y-1] = *(it++);
    }
  }
  sort(c.begin(), c.end());
  ll sum = 0;
  for(ll i=0; i+1<N; i++)
    sum+=c[i];
  std::cout << sum << std::endl;
  for(ll i=0; i<N; i++) {
    if(i+1 < N) 
      std::cout << ans[i] << " ";
    else
      std::cout << ans[i];
  }
  std::cout << std::endl;
}

int main(){
  long long N;
  scanf("%lld",&N);
  std::vector<long long> a(N-1);
  std::vector<long long> b(N-1);
  for(int i = 0 ; i < N-1 ; i++){
    scanf("%lld",&a[i]);
    scanf("%lld",&b[i]);
  }
  std::vector<long long> c(N);
  for(int i = 0 ; i < N ; i++){
    scanf("%lld",&c[i]);
  }
  solve(N, std::move(a), std::move(b), std::move(c));
  return 0;
}

