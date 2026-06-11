#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
#define all(x) (x).begin(),(x).end()


int main() {
  int N;
  cin >> N;
  vector<vector<int>> openStore(N, vector<int>(10));
  vector<vector<ll>> point(N, vector<ll>(11));
  for(int i=0; i<N; i++){
    for(int j=0; j<10; j++){
      cin >> openStore[i][j];
    }
  }
  for(int i=0; i<N; i++){
    for(int j=0; j<=10; j++){
      cin >> point[i][j];
    }
  }

  ll maxScore = -1000000000000;
  for (int bit = 1; bit < (1 << 10); ++bit) {
    vector<int> openJ(10,0);
    for (int i = 0; i < 10; ++i) {
       if (bit & (1 << i)) openJ[9 - i] = 1;
    }

    vector<int> dock(N, 0);
    for(int i=0; i<N; i++){
      for(int j=0; j<10; j++){
        if(openJ[j] == 1 && openStore[i][j] == 1) dock[i]++;
      }
    }

    ll sum = 0;
    for(int i=0; i<N; i++){
      sum += point[i][dock[i]];
    }
    maxScore = max(maxScore, sum);
  }

  cout << maxScore << ln;
 }
