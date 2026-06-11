#include <bits/stdc++.h>
using namespace std;

int main(){
  int H, W, N, sr, sc;
  cin >> H >> W >> N >> sr >> sc;
  string S, T;
  cin >> S >> T;
  int tL=0, tR=0, tU=0, tD=0, aL=0, aR=0, aU=0, aD=0;
  for (int i=0; i<N; i++){
    if (S[i]=='L') tL++;
    else if (S[i]=='R') tR++;
    else if (S[i]=='U') tU++;
    else tD++;
    if (sc+aR-tL<1||tR+sc-aL>W||sr+aD-tU<1||tD+sr-aU>H){
      cout << "NO" << endl;
      return 0;
    }
    if (T[i]=='L') {
      if (tR+sc-aL>1) aL++;
    }
    else if (T[i]=='R') {
      if (sc-tL+aR<W) aR++;
    }
    else if (T[i]=='U') {
      if (tD+sr-aU>1) aU++;
    }
    else {
      if (sr-tU+aD<H) aD++;
    }
  }
  cout << "YES" << endl;
}
