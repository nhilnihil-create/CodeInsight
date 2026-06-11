#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,Y;
  cin >> N >> Y;
  
  int x=-1,y=-1,z=-1;
  bool can = false;
  
  for(int i=0;i<=N;i++){
    for(int j=0;j<=N;j++){
      int k = N-i-j;  
      if(10000*i+5000*j+1000*k==Y && k>=0){
        x=i;
        y=j;
        z=k;
        can=true;
      }
      if(can==true){
        break;
      }
    }
    if(can==true){
      break;
    }
  }
  
  cout << x << ' ' << y << ' ' << z << endl;
  return 0;
  
}