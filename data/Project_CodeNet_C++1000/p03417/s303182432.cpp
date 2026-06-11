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
  ll N, M;
  cin >> N >> M;

  if((N == 1) && (M == 1)){
    cout << 1 << endl;
    return 0;
  }

  if((N == 1) || (M == 1)){
    cout << N * M - 2 << endl;
    return 0;
  }

  if((N == 2) || (M == 2)){
    cout << 0 << endl;
    return 0;
  }

  cout << (N - 2) * (M - 2) << endl;
  
  return 0;
}
