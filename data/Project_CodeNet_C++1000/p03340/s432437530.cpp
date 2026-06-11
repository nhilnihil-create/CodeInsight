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


int main() {
  int N;
  cin >> N;
  vector<int> AN(N);
  REP(n,N){
    int tmp;
    cin >> tmp;
    AN[n] = tmp;
  }


  ll ans = 0;
  int sum = 0;
  int l, r;
  l = 0;
  r = 0;
  for (l=0; l < N; l++){
    while(r < N && ((sum ^ AN[r]) == (sum + AN[r])) ){
      sum += AN[r];
      r += 1;
    }
    ans += (r-l);
    if (l==r){
      r+=1;
    } else{
       sum -= AN[l];
    }

  }
  cout << ans << endl;
}
