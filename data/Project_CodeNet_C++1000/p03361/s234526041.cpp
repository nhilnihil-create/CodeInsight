#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using ld = long double;
const ll ATCODER_AMARI = 1000000007; //10^9 + 7
const ll INF = 10000000000000;

//階乗関数　ATCODER_AMARIに注意
ll factorial(ll k){
  ll sum = 1;
  for(int i = 1 ; i < k + 1; i++) {
    sum *= i;
    //sum = sum % ATCODER_AMARI;
  }
  return sum;
}

int main() {
  int h,w;
  cin >> h >> w;

  vector<vector<char>> s(h,vector<char>(w));
  
  rep(i,h) {
    rep(j,w) {
      cin >> s.at(i).at(j);
    }
  }

  bool flag = true;

  rep(i,h) {
    rep(j,w) {

      char tmp = s.at(i).at(j);

      if(tmp == '#') {
        if(i != 0) {
          if(s.at(i - 1).at(j) == '#') continue;
        }
        if(i != h - 1) {
          if(s.at(i + 1).at(j) == '#') continue;
        }
        if(j != 0) {
          if(s.at(i).at(j - 1) == '#') continue;
        }
        if(j != w - 1) {
          if(s.at(i).at(j + 1) == '#') continue;
        }

        flag = false;
        
      }
      
    }
  }


  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl;
}
