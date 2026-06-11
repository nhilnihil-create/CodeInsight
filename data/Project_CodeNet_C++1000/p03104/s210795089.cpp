#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
using LP = pair<int, int>;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const double PI=3.14159265358979323846;

int mod = 1e9+7;
const long long INF = 1LL<<60;


ll count_pop(ll e, int keta){
  // [0, s]のketa桁目のpopulationを返す
  ll unit = (ll)pow(2, (ll)keta);

  // if(keta < 4){
  //   cout << "unit:" << unit << endl;
  // }

  ll div_cnt = e / unit;
  ll div_mod = e % unit;

  ll ans = 0;
  ans += (div_cnt/2) * unit;
  if(div_cnt%2==1){
    ans += 1 + div_mod;
  }

  return ans;
}

int main(){
  ll A, B;
  cin >> A >> B;

  vector<ll> population(64);
  rep(keta, 64){
    // if(keta < 4){
    //   cout << "===" << endl;
    //   cout << "keta:" << keta << endl;
    //   cout << "B:" << B << endl;
    //   cout << "A-1:" << A-1 << endl;
    //   cout << "cout_pop(B, keta):" << count_pop(B, keta) << endl;
    //   cout << "cout_pop(A-1, keta):" << count_pop(A-1, keta) << endl;
    // }
    population[keta] = count_pop(B, keta) - count_pop(A-1, keta);
  }

  ll ans = 0;
  rep(i, 64){
    ll tmp = 1LL<<(ll)i;
    if(population[i]%2==1){
      ans += tmp;
    }
  }

  cout << ans << endl;

  return 0;
}
