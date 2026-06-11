#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  int i=0;
  int p=0;
  int w=0;
  int g=0;
  int y=0;
  string hinaColor="";
  
  cin >> N;
  while(i<N){
    cin >> hinaColor;
      if(hinaColor=="P"){
        p++;
      }else if(hinaColor=="W"){
        w++;
      }else if(hinaColor=="G"){
        g++;
      }else if(hinaColor=="Y"){
        y++;
      }
    i++;
  }
  
  if(p>0 && w>0 && g>0 && y>0){
    cout << "Four" <<endl;
  }else if(p>0 && w>0 && g>0){
    cout << "Three" <<endl;
  }
}
