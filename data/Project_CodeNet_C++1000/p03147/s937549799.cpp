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
  vl h(N);
  rep(i, N) cin >> h[i];
  
  ll ans = 0;
  ll flag = 0;

  rep2(i, 1, 101){
    flag = 0;

    rep(j, N){
      if((flag == 0) && (h[j] >= i))
	flag = 1;
      else if((flag == 1) && (h[j] < i)){
	ans++;
	flag = 0;
      }
    }

    if(flag == 1)
      ans++;
  }

  cout << ans << "\n";
  
  return 0;
}
