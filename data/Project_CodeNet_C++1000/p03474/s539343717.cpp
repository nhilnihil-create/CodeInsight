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
  ll A, B;
  cin >> A >> B;
  string S;
  cin >> S;

  ll cnt = 0;
  ll pos = 0;

  rep(i, A + B + 1){
    if(S[i] == '-'){
      cnt++;
      pos = i;
    }
  }

  if((cnt == 1) && (pos == A))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  
  return 0;
}
