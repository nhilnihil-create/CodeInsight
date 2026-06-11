#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
const int MOD =  1000000007;
const int INF = 1e11;
using Graph = vector<vector<int>>;

signed main(){

  //100以下の素数
  vector<int> prime;
  for( int i = 2; i <= 100; i++ ){
    bool fg = 1;
    for( int j = 2; j < i; j++ ){
      if( i%j == 0 ) fg = 0;
    }
    if( fg ) prime.push_back(i);
  }

  int N;
  cin >> N;

  int p = (int)prime.size();

  //N!の素因数分解
  vector<int> fac(p+10);
  for( int i = 1; i <= N; i++ ){
    int n = i;
    for( int j = 0; j < p; j++ ){
      while( n%prime[j] == 0 ){
        n /= prime[j];
        fac[j]++;
      }
    }
  }

  int ans = 0;

  //p^74
  for( int i = 0; i < p; i++ ){
    if( fac[i] >= 74 ) ans++;
  }

  //p^2*q^24 or p^4*q^14
  for( int i = 0; i < p; i++ ){
    for( int j = 0; j < p; j++ ){
      if( i == j ) continue;
      int a = fac[i];
      int b = fac[j];
      if( a>=2 && b>=24 ) ans++;
      if( a >= 4 && b >= 14 ) ans++;
    }
  }

  //p^2*r^4*r^4
  for( int i = 0; i < p; i++ ){
    for( int j = 0; j < p; j++ ){
      for( int k = j+1; k < p; k++ ){
        if( i == j || i == k ) continue;
        if( fac[i] >= 2 && fac[j] >= 4 && fac[k] >= 4 ) ans++;
      }
    }
  }

  cout << ans << endl;
}