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
  ll N, M, X, Y;
  cin >> N >> M >> X >> Y;
  vl x(N), y(M);
  rep(i, N) cin >> x[i];
  rep(i, M) cin >> y[i];

  stable_sort(x.begin(), x.end(), greater<ll>());
  stable_sort(y.begin(), y.end());

  if(x[0] > y[0]){
    cout << "War\n";
    return 0;
  }

  rep2(Z, X + 1, Y + 1){
    if((x[0] < Z) && (Z <= y[0])){
      cout << "No War\n";
      return 0;
    }
  }

  cout << "War\n";
  
  return 0;
}
