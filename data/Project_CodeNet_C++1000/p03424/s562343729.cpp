#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,p,w,g,y;
  cin >> N;
  p=0;
  w=0;
  g=0;
  y=0;
  
  string si;
  for (int i=0;i<N;i++){
    cin >> si;
    if (si=="P"){
      p=1;
    }
    else if (si=="W"){
      w=1;
    }
    else if (si=="G"){
      g=1;
    }
    else if (si=="Y"){
      y=1;
    } 
  }
  if (p==1&&w==1&&g==1&&y==1){
    cout << "Four" << endl;
  }
  else {
    cout << "Three" <<endl;
  }
}