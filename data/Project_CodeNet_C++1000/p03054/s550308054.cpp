#include<bits/stdc++.h>
using namespace std;
int H, W, N, Sy, Sx;
bool in(int l, int r, int p){
  return p <= r && p >= l;
}
int main(){
  cin >> H >> W >> N >> Sy >> Sx;
  Sy--;Sx--;
  string S, T; cin >> S >> T;
  int R = W - 1, L = 0, D = H - 1, U = 0;
  bool f = true;
  for(int i = N - 1; i >= 0 && f; --i){
    switch(T[i]){
    case 'U':
      if(D != H - 1)D++;
      break;
    case 'D':
      if(U != 0)U--;
      break;
    case 'R':
      if(L != 0)L--;
      break;
    case 'L':
      if(R != W - 1)R++;
    }
    switch(S[i]){
    case 'U':U++;break;
    case 'D':D--;break;
    case 'R':R--;break;
    case 'L':L++;break;      
    }
    if(R < L)f = false;    
    if(D < U)f = false;    
  }
  f &= in(L,R,Sx);
  f &= in(U,D,Sy);
  cout << (f?"YES":"NO") << endl;
  return 0;
}
