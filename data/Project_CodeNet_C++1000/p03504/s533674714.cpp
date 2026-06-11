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
  int N,C,s,t,c;
  cin >> N >> C;
  vector<vector<int>> pp(1e5,vector<int>(C,0)); 
  rep(i,N){
    cin >> s >> t >> c;
    c--;s--;t--;
    pp[s][c] += 1;
    pp[t][c] -= 1;
  }

  vector<int> memo(C,0);
  int ans=0;
  rep(i,1e5) {
    rep(j,C) {
      if (pp[i][j]==1) memo[j]=1;
      }
    chmax(ans,accumulate(memo.begin(),memo.end(),0));
    rep(j,C) {
      if (pp[i][j]==-1) memo[j]=0;
      }
  }

  cout << ans << endl;
}