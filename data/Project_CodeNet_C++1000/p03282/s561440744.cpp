#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const long long INF = 1LL << 60;
const ll MOD = 1000000007;
using pint = pair<ll, ll>;

int main() {
  string S;
  cin >> S;
  ll K;
  cin >> K;
  bool all1 = true;
  for (int i = 0; i < S.size(); i++) {
    if (S[i] != '1') all1 = false;
  }
  if(all1){
      cout << 1 << endl;
      return 0;
  }


  if(K<=S.size()){
      for(int i = 0; i < K; i++){
          if(S[i]!='1'){
              cout << S[i] << endl;
              return 0;
          }
      }
      cout << 1 << endl;
      return 0;
  }

  for(int i = 0; i < S.size(); i++){
      if(S[i] !='1'){
        cout << S[i] << endl;
        return 0;
      }
  }
}