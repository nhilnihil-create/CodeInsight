#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep_inv(i, n, m) for(int i = (int)(n); i > (int)(m); i--)
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vc = vector<char>;
using vvl = vector<vl>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

int main(){
  ll N;
  cin >> N;
  vl X(N), Y(N);  
  rep(i, N){
    cin >> X[i];
    Y[i] = X[i];
  }

  stable_sort(Y.begin(), Y.end());

  ll ord;

  rep(i, N){
    ord = lower_bound(Y.begin(), Y.end(), X[i]) - Y.begin();
    if((ord + 1) <= N / 2) cout << Y[N / 2] << endl;
    else cout << Y[N / 2 - 1] << endl;
  }
  
  
  return 0;
}
