#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pl = pair<ll,ll>;
#define inf numeric_limits<ll>::max()

template <class T> ostream &operator<<(ostream &os, vector<T> &v) {
  for (auto i = v.begin(); i != v.end(); i++) {
    os << *i << " ";
  }
  return os;
}

ll nn(vector<ll> &v, ll x) {
  auto it = lower_bound(v.begin(), v.end(), x);
  ll w, e;
  if(it == v.begin())
    w = inf;
  else
    w = abs(*prev(it)-x);
  if(it == v.end())
    e = inf;
  else
    e = abs(*it-x);
  return min(w, e);
}

void solve(long long A, long long B, long long Q, std::vector<long long> s, std::vector<long long> t, std::vector<long long> x){
  vector<pair<ll,char>> v;
  for(auto xx : s) {
    v.push_back(make_pair(xx, 's'));
  }
  for(auto xx : t) {
    v.push_back(make_pair(xx, 't'));
  }
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());
  sort(v.begin(), v.end());
  
  for(auto val: x) {
    auto it = lower_bound(v.begin(), v.end(), make_pair(val, 'a'));
    ll w, e;
    //first west
    if(it == v.begin()) {
      w = inf;
    } else {
      w = abs(val - prev(it)->first);
      if(prev(it)->second == 's')
	w += nn(t, prev(it)->first);
      else
	w += nn(s, prev(it)->first);
    }
    //first east
    if(it == v.end())
      e = inf;
    else {
      e = abs(val - it->first);
      if(it->second == 's')
	e += nn(t, it->first);
      else
	e += nn(s, it->first);
    }

    std::cout << min(w, e) << std::endl;
  }
}

int main(){
  long long A;
  scanf("%lld",&A);
  long long B;
  scanf("%lld",&B);
  long long Q;
  scanf("%lld",&Q);
  std::vector<long long> s(A);
  for(int i = 0 ; i < A ; i++){
    scanf("%lld",&s[i]);
  }
  std::vector<long long> t(B);
  for(int i = 0 ; i < B ; i++){
    scanf("%lld",&t[i]);
  }
  std::vector<long long> x(Q);
  for(int i = 0 ; i < Q ; i++){
    scanf("%lld",&x[i]);
  }
  solve(A, B, Q, std::move(s), std::move(t), std::move(x));
  return 0;
}
