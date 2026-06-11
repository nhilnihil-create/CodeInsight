#include <bits/stdc++.h>
#include <iostream>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,a,b) for(int i=(a);i<(b);++i)

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

template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

int main() {
  int N,f;
  ll p;
  cin >> N;
  vector<vector<int>> F(N),P(N);
  rep(i,N)rep(j,10){
    cin >> f;
    F[i].push_back(f);
  }
  rep(i,N)rep(j,11){
    cin >> p;
    P[i].push_back(p);
  }

  ll ans = LONG_LONG_MIN,tans;
  for (int i=1;i<(1<<10);i++) {
    vector<int> memo(N,0);
    rep(j,10) if (i>>j&1) {
      rep(k,N) if (F[k][j]) memo[k]++;
    } 
    tans=0;
    rep(j,N){
      tans += P[j][memo[j]];
    }
    
    chmax(ans,tans);
  }
  cout << ans << endl;  
}