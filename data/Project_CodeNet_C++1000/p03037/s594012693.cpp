#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int N,M;
  cin >> M >> M;
  vector<int> L(M),R(M);
  for(int i=0;i<M;i++){
    cin >> L[i] >> R[i];
  }
  sort(L.begin(),L.end());
  sort(R.begin(),R.end());
  if(R[0]-L[M-1]+1>=0){
    cout << R[0]-L[M-1]+1 << endl;
    return 0;
  }
  else{
    cout << 0 << endl;
    return 0;
  }
}