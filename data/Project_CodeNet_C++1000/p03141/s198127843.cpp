#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <class T> ostream &operator<<(ostream &os, vector<T> &v) {
  for (auto i = v.begin(); i != v.end(); i++) {
    os << *i << " ";
  }
  return os;
}


void solve(long long N, std::vector<long long> A, std::vector<long long> B){
  vector<pair<ll, ll>> v;
  ll t = 0;
  ll a = 0;
  for(ll i=0; i<N; i++) {
    v.push_back(make_pair(A[i]+B[i], i));
  }
  sort(v.rbegin(), v.rend());
  for(ll i=0; i<N; i++) {
    if(i%2==0)
      t+=A[v[i].second];
    else
      a+=B[v[i].second];
  }
  std::cout << t-a << std::endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> A(N);
    std::vector<long long> B(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
        scanf("%lld",&B[i]);
    }
    solve(N, std::move(A), std::move(B));
    return 0;
}
