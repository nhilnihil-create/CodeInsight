#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const int MAX = 510000;

int main() {
  ll N, M;
  cin >> N >> M;
  if (N>=3&&M>=3) cout << (N-2)*(M-2) << endl;
  else if ((N==2&&M>=2)||(N>=2&&M==2)) cout << 0 << endl;
  else if (N==1&&M!=1) cout << M-2 << endl;
  else if (N!=1&&M==1) cout << N-2 << endl;
  else if (N==1&&M==1) cout << 1 << endl;
}