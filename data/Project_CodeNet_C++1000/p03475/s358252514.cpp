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
  vvl csf(N - 1, vl(3));
  rep(i, N - 1) cin >> csf[i][0] >> csf[i][1] >> csf[i][2];

  rep(i, N){
    ll station = i;
    ll x = 0;
    while(station < N - 1){
      if(x <= csf[station][1]){
	x = csf[station][1] + csf[station][0];
      } else{
	if(x % csf[station][2] == 0){
	  x += csf[station][0];
	} else{
	  x = (x / csf[station][2] + 1) * csf[station][2] + csf[station][0];
	}
      }
      station++;
    }
    cout << x << endl;
  }
  
  return 0;
}
