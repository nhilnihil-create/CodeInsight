#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const int MAX = 510000;

// (10進法での)桁数
int dignum10(ll n) {
  int res = 0;
  while(n>0) {
    res++;
    n /= 10;
  }
  return res;
}

int main() {
  ll N;
  cin >> N;
  int K = dignum10(N), c = N/pow(10, K-1), ans = 0;
  bool flag = false;
  for (int i=0; i<=16; i++) {
    if ((ll)(c+1)*pow(10, i)-1==N) {
      flag = true;
      break;
    }
  }
  if (flag) ans = c+9*(K-1);
  else ans = c+9*(K-1)-1;
  cout << ans << endl;
}