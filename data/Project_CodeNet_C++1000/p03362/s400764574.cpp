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

ll Maxi = 55555;
ll N;
vl prm;

int main(){
  cin >> N;

  vl furui(Maxi + 1, 1);
  furui[0] = 0;
  furui[1] = 0;

  rep(i, Maxi){
    if(furui[i] == 0) continue;

    prm.push_back(i);

    ll j = 2*i;
    while(j < Maxi + 1){
      furui[j] = 0;
      j += i;
    }
  }

  rep(i, prm.size()){
    if(prm[i] % 5 == 1){
      cout << prm[i] << ' ';
      N--;
    }
    if(N == 0){
      cout << "\n";
      return 0;
    }
  }
  
  return 0;
}
