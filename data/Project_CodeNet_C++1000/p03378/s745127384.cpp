#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M, X;
  cin >> N >> M >> X;
  vector<int>A(M);
  int ans=0;
  int go0 =0;
  int goN =0;
  for(int i=0; i<M; i++)cin >> A.at(i);
  
  for(int i=0; i<M; i++){
    if(A.at(i)<X)go0 ++;
    else goN ++;
  }
  
  if(go0<goN)ans=go0;
  else ans = goN;
  
  cout << ans << endl;
}