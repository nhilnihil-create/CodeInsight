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

  vvl ss(26), tt(26);

  rep(i, S.size()){
    ss[S[i] - 'a'].push_back(i);
    tt[T[i] - 'a'].push_back(i);
  }

  stable_sort(ss.begin(), ss.end());
  stable_sort(tt.begin(), tt.end());

  rep(i, 26){
    if(!(ss[i] == tt[i])){
      cout << "No\n";
      return 0;
    }
  }

  cout << "Yes\n";
  
  return 0;
}
