#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M,X=0.;
  cin >> N >> M;
  vector<int>L(M);
  vector<int>R(M);
  for(int i=0; i<M; i++){
    cin >> L[i] >> R[i];
  }
  sort(L.begin(),L.end());
  sort(R.begin(),R.end());
  if(R[0]-L[M-1] >= 0){
    cout << R[0]-L[M-1]+1 << endl;
    return 0;
  }
  cout << 0 << endl;
}
