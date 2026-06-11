#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
/*
*/
//約数の列挙
vector<ll> divisor(ll n){
    vector<ll> res;//約数を格納する列
    for(ll i= 1;i*i <= n;i++){
        if(n % i == 0){
           res.push_back(i);
           if(i != n/i) res.push_back(n/i);
         }
    }
    return res;
}

int main() {
  ll N;
  cin >> N;
  vector<ll> res = divisor(N);//Nの約数の列
  ll ans = 0;
  for(int i = 0;i<res.size();i++){
      ll m = res[i]-1;
      if(m != 0 && N/m == N%m) ans += m;
  }
  cout << ans << endl;

}