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
  string S;
  ll K;
  cin >> S >> K;

  ll cnt_one = 0;
  while((S[cnt_one] == '1') && (cnt_one < S.size())) cnt_one++;

  if((cnt_one == S.size()) || (cnt_one >= K)){
    cout << 1 << endl;
    return 0;
  }

  cout << S[cnt_one] << endl;
  
  return 0;
}
