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
  string S, T;
  cin >> S >> T;

  if(S == T){
    cout << "Yes" << endl;
    return 0;
  }

  ll n = S.size();

  rep2(i, 1, n){
    if((S.substr(0, i) == T.substr(n - i, i)) && (S.substr(i, n - i) == T.substr(0, n - i))){
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;
  
  return 0;
}
