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
  ll s;
  cin >> s;

  ll a = s;
  set<ll> num;
  num.insert(a);
  ll i = 1;

  while(true){
    if(a % 2 == 0)
      a /= 2;
    else
      a = 3*a + 1;

    if(num.count(a) == 1){
      cout << i + 1 << "\n";
      return 0;
    }

    num.insert(a);
    i++;
  }
  
  return 0;
}
