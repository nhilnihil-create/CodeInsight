#include <bits/stdc++.h>
using namespace std;
int main () {
  long N, M;
  string S, T;
  cin >> N >> M >> S >> T;
  long L = (N * M) / __gcd(N, M);
  long npl = 0, mpl = 0, flag = 1;
  while(npl != N && mpl != M){
    if(npl * L / N == mpl * L / M){
      if(S.at(npl) != T.at(mpl)){
        flag = 0;
        break;
      }
      npl++;
      mpl++;
    } else if(npl * L / N > mpl * L / M){
      mpl++;
    } else {
      npl++;
    }
  }
  cout << (flag?L:-1) << endl;
  return 0;
}