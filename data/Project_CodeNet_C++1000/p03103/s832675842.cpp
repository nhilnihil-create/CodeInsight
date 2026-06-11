#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,val) for(int i = 0; i < val; i++)

bool has_key(unordered_map<string, ll> &m, string s){
    if (m.find(s) == m.end()){
        return false;
    }
    else{
        return true;
    }
}


bool vector_find(std::vector<ll> vec, ll number) {
  auto itr = std::find(vec.begin(), vec.end(), number);
  size_t index = std::distance( vec.begin(), itr );
  if (index != vec.size()) {
    return true;
  }
  else {
    return false;
  }
}


void recursive_comb(int *indexes, int s, int rest, std::function<void(int *)> f) {
  if (rest == 0) {
    f(indexes);
  } else {
    if (s < 0) return;
    recursive_comb(indexes, s - 1, rest, f);
    indexes[rest - 1] = s;
    recursive_comb(indexes, s - 1, rest - 1, f);
  }
}


void foreach_comb(int n, int k, std::function<void(int *)> f) {
  int indexes[k];
  recursive_comb(indexes, n - 1, k, f);
}



int main() {
    
    ll N, M;
    cin >> N >> M;

    vector<ll> A(N);
    vector<ll> B(N);
    vector<vector<ll>> C(N, vector<ll>(2));

    for (ll i = 0; i < N; i++) {
      cin >> C.at(i).at(0) >> C.at(i).at(1);
    }
    

    sort(C.begin(),C.end(),[](const vector<ll> &alpha,const vector<ll> &beta){return alpha[0] < beta[0];});

    ll ans = 0;

    for (ll i = 0; i < N; i++) {
      
      if (C.at(i).at(1) < M) {
        M = M - C.at(i).at(1);
        ans = ans + C.at(i).at(1) * C.at(i).at(0);
      } else {
        ans = ans + M * C.at(i).at(0);
        break;
      }
    }
    

    cout << ans << endl;


    return 0;
}