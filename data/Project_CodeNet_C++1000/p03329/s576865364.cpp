#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
using ll = long long;
using namespace std;

const long long MOD = 1000000007;
const ll LINF = 1LL << 50;


template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
  int N;
  cin >> N;
  //vector<ll> hn(100010, 0);
  vector<ll> dp(1000010, LINF);

  int ninemax = 0;
  while (true){
    if (N < pow(9,ninemax)){
      break;
    } else{
      ninemax +=1;
    }
  }
  int sixmax = 0;
  while (true){
    if (N < pow(6,sixmax)){
      break;
    } else{
      sixmax +=1;
    }
  }

  int ans = 0;

  // initialize
  REP(n,N+1){
    dp.at(n) = n;
  }
  for (int n = 0; n<=N; n++){
    for (int m = 0; m < ninemax; m++) chmin(dp.at(n+pow(9,m)), dp.at(n)+1);
    for (int m = 0; m < sixmax;  m++) chmin(dp.at(n+pow(6,m)), dp.at(n)+1);
  }

  cout << dp.at(N) << endl;

}
