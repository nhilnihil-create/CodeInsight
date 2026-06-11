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
#include <limits>
using namespace std;
using ll = long long int;
#define inf numeric_limits<ll>::max()

template <class T> ostream &operator<<(ostream &os, vector<T> &v) {
  for (auto i = v.begin(); i != v.end(); i++) {
    os << *i << " ";
  }
  return os;
}


void solve(long long N, long long C, std::vector<std::vector<long long>> D, std::vector<std::vector<long long>> c){
  ll ans = inf;
  vector<ll> x(C, 0);
  vector<ll> y(C, 0);
  vector<ll> z(C, 0);

  for(ll i=0; i<C; i++) {
    for(ll j=0; j<N; j++) {
      for(ll k=0; k<N; k++) {
	if((j+k+2) % 3 == 0) {
	  x[i] += D[c[j][k]-1][i];
	} else if((j+k+2) % 3 == 1) {
	  y[i] += D[c[j][k]-1][i];
	} else {
	  z[i] += D[c[j][k]-1][i];
	}
      }
    }
  }

  //std::cout << "!!!" << std::endl;
  
  for(ll i=0; i<C; i++) {
    for(ll j=i+1; j<C; j++) {
      for(ll k=j+1; k<C; k++) {
	vector<ll> col = {i, j, k};
	do {
	  ans = min(ans, x[col[0]]+y[col[1]]+z[col[2]]);
	} while(next_permutation(col.begin(), col.end()));
      }
    }
  }
  std::cout << ans << std::endl;
}

int main(){
  long long N;
  scanf("%lld",&N);
  long long C;
  scanf("%lld",&C);
  std::vector<std::vector<long long>> D(C, std::vector<long long>(C));
  for(int i = 0 ; i < C ; i++){
    for(int j = 0 ; j < C ; j++){
      scanf("%lld",&D[i][j]);
    }
  }
  std::vector<std::vector<long long>> c(N, std::vector<long long>(N));
  for(int i = 0 ; i < N ; i++){
    for(int j = 0 ; j < N ; j++){
      scanf("%lld",&c[i][j]);
    }
  }
  solve(N, C, std::move(D), std::move(c));
  return 0;
}

