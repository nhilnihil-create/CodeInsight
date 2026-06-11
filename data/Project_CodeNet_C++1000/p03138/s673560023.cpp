#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef int64_t Int;
using namespace std;

int MSB(bitset<40> b){
  int res = -1;
  rep(i, 40) if(b[i] == 1) res = i;
  return res;
}

Int toI(bitset<40> b){
  Int k = 1, res = 0;
  rep(j, 40){
    if(b[j] == 1) res += k; k *= 2;
  }
  return res;
}

int main(){
  Int N, K;
  vector<bitset<40>> A(100010);
  vector<int> cnt(40, 0);

  cin >> N >> K;

  rep(i, N){
    Int a; cin >> a;
    A[i] = bitset<40>(a);

    rep(j, 40){ if(A[i][j] == 1) cnt[j]++;}
  }

  bitset<40> X; int msb = MSB(K);
  for(int i=39; i>=0; i--){
    if(cnt[i] <= N/2 && i <= msb) X[i] = 1;
    else X[i] = 0;

    if(toI(X) > K) X[i] = 0;
  }

  Int ans = 0;
  rep(i, N){
    bitset<40> tmp = X ^ A[i];
    ans += toI(tmp);
  }

  cout << ans << endl;
}


