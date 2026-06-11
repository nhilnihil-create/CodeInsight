#include <iostream>
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
  int pos = sc;
  rep(i, N) {
    if (S[i] == 'R')
      ++pos;
    if (pos > W) {
      cout << no << endl;
      return 0;
    }
    if (T[i] == 'L')
      pos = max(pos-1, 1);
  }

  pos = sc;
  rep(i, N) {
    if (S[i] == 'L')
      --pos;
    if (pos < 1) {
      cout << no << endl;
      return 0;
    }
    if (T[i] == 'R')
      pos = min(pos+1, W);
  }


  pos = sr;
  rep(i, N) {
    if (S[i] == 'D')
      ++pos;
    if (pos > H) {
      cout << no << endl;
      return 0;
    }
    if (T[i] == 'U')
      pos = max(pos-1, 1);
  }

  pos = sr;
  rep(i, N) {
    if (S[i] == 'U')
      --pos;
    if (pos < 1) {
      cout << no << endl;
      return 0;
    }
    if (T[i] == 'D')
      pos = min(pos+1, H);
  }
  cout << yes << endl;
  return 0;

}
