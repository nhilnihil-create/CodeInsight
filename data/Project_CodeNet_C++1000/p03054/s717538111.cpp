#include <iostream>
#include <map>
using namespace std;
void ins() {}
template<class T,class... Rest>void ins(T& v,Rest&... rest){cin>>v;ins(rest...);}
#define rep(i,n) for(int i=0,_i=(n);i<_i;++i)

const string yes = "YES", no = "NO";
int main() {
  int H, W, N; ins(H, W, N);
  int sr, sc;  ins(sr, sc);
  string S, T; ins(S, T);


  // R方向に動かして落とす
  rep(k, 2) {
    map<char, int> d;
    if (k) d['R'] = 1, d['L'] = -1;
    else   d['D'] = 1, d['U'] = -1;
    rep(j, 2) {
      int dx = 2*j-1;
      int pos = k ? sc : sr,
          limit = k ? W : H;
      rep(i, N) {
        if (d[S[i]] == dx)
          pos += dx;
        if (pos > limit || pos < 1) {
          cout << no << endl;
          return 0;
        }
        if (d[T[i]] == -dx)
          pos = min(limit, max(pos-dx, 1));
      }
    }
  }

  cout << yes << endl;
  return 0;
}
