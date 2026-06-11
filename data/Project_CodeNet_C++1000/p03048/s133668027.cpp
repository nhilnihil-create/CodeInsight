#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int R, G, B, N, Sum=0;
  cin >> R >> G >> B >> N;
  rep(i, N/R+1){
    if(R*i>N) break;
    rep(j, N/G+1){
      if(R*i+G*j>N) break;
      if((N-(R*i+G*j))%B==0) Sum++;
    }
  }
  cout << Sum << endl;
}