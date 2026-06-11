#include <bits/stdc++.h>
#include <fstream>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,a,b) for(int i=(a);i<(b);++i)

template<class T> inline void chmin(T& a, T b) {if (a > b) a = b;}
template<class T> inline void chmax(T& a, T b) {if (a < b) a = b;}


int main() {
  // ofstream ofstr(".¥¥test.txt" );
  // streambuf* strbuf;
  // strbuf = std::cout.rdbuf( ofstr.rdbuf() );

  int A,B;
  cin >> A >> B;
  int s = min(A,B), l = max(A,B);
  vector<vector<char>> ans(100, vector<char>(100,'.'));
  s--;

  rep(i,25){
    rep(j,25) {
      if (l>0) {
        l--;
        rep(x,3)rep(y,3) ans[i*4+x][j*4+y] = '#';
        if (s>0) {s--;ans[i*4+1][j*4+1]='.';}
      }
    }
  }
  cout << 100 << ' ' << 100 << endl;
  rep(i,100){
    rep(j,100) {
      if (A>B) {
        if (ans[i][j]=='.') ans[i][j] = '#';
        else ans[i][j] = '.';
      }
      cout << ans[i][j];
    }
    cout << endl;
  }
  

  // cout.rdbuf( strbuf );
} 