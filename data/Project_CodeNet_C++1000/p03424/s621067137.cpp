#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string S;

  cin >> N;
  
  int Np = 0, Nw = 0, Ng = 0, Ny = 0;
  int Nt;
//cout << Np << Nw << Ng << Ny << endl;
  
  for(int i = 0;i < N; i++) {
    
    cin >> S;
//  cout << S << endl;
   
    if(S == "P" && Np == 0) {
      Np++;
//    cout << Np << endl;
    }

    if(S == "W" && Nw == 0) {
      Nw++;
//    cout << Nw << endl;
    }
    
    if(S == "G" && Ng == 0) {
      Ng++;
//    cout << Ng << endl;
    }
    
    if(S == "Y" && Ny == 0) {
      Ny++;
//    cout << Ny << endl;
    }
    
  Nt = Np + Nw + Ng + Ny;
//cout << Nt << endl;
    
  if(Nt == 4) {
    cout << "Four" << endl;
    break;
  }
    
  }

  if(Nt == 3) {
    cout << "Three" << endl;
  }
  
}