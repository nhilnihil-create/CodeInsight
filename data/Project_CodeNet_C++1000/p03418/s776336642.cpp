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
  ll N, K;
  cin >> N >> K;

  if(K == 0){
    cout << N*N << endl;
    return 0;
  }

  ll cnt = 0;

  rep2(b, K + 1, N + 1) cnt += N / b * (b - K) + max((N % b) - (K - 1), (ll)0);

  cout << cnt << endl;
  
  return 0;
}
