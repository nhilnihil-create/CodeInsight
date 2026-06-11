#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template <class T> ostream &operator<<(ostream &os, vector<T> &v) {
  for (auto i = v.begin(); i != v.end(); i++) {
    os << *i << " ";
  }
  return os;
}


void solve(long long N){
  vector<ll> v(N+1);
  vector<pair<ll, ll>> ans;

  if(N%2==0) {
    for(ll i=1; i<=N/2; i++) {
      v[i] = N-i+1;
      v[N-i+1] = i;
    }
  } else {

    for(ll i=1; i<=N/2; i++) {
      v[i] = N-i;
      v[N-i] = i;
    }
    v[N] = 0;
  }
  for(ll i=1; i<=N; i++) {
    for(ll j=i+1; j<=N; j++) {
      if(j==v[i]) continue;
      ans.push_back(make_pair(i, j));
    }
  }
  std::cout << ans.size() << std::endl;
  for(auto p: ans) {
    std::cout << p.first <<" "<<p.second << std::endl;
  }

  
  
}

int main(){
  long long N;
  scanf("%lld",&N);
  solve(N);
  return 0;
}
