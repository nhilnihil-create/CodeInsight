#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  char C;
  bool G, W, Y, P;
  G = W = Y = P = false;
  cin >> N;
  for(int i=0;i<N;i++){
	cin >> C;
    if(C == 'G') G = true;
    if(C == 'W') W = true;
    if(C == 'Y') Y = true;
    if(C == 'P') P = true;
  }
  if(G && W && Y && P){
    cout << "Four" << endl;
  }else{
    cout << "Three" << endl;
  }
}