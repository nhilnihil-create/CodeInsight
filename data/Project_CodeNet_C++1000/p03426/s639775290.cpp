#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int H,W,D;cin >> H >> W >> D;
  vector<int> X(H*W+1);
  vector<int> Y(H*W+1);
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      int a;cin >> a;
      X[a] = i;
      Y[a] = j;
    }
  }
  vector<vector<ll>> C(D,vector<ll>(0));
  for(int d=0;d<D;d++){
    C[d].push_back(0);
    for(int i=1;i*D+d<=H*W;i++){
      int curcost = C[d][i-1] + abs(X[i*D+d]-X[(i-1)*D+d]) + abs(Y[i*D+d]-Y[(i-1)*D+d]);
      C[d].push_back(curcost);
    }
  }
  int Q;cin >> Q;
  for(int q=0;q<Q;q++){
    int L,R;cin >> L >> R;
    int x = L%D;
    L = (L-x)/D;
    R = (R-x)/D;
    cout << C[x][R] - C[x][L] << endl;
  }
}