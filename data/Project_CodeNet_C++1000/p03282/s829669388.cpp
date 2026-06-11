#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (ll)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;



int main() {
  string S;
  ll K;
  cin >>S >> K;
  rep(i,K){
  if (S[i] != '1'){
      cout << S[i] << endl;
      return 0;
    }
  
  }
  
  cout << 1 << endl;



  return 0;
}






