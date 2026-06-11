#include <bits/stdc++.h>
using namespace std;

signed main(){
  unsigned long long int X,Y;
  cin >> X >> Y;
  for(unsigned long long int i=1;i<3;i++){
    if(X*i%Y!=0){
      cout << X*i << endl;
      break;
    }
    if(i==2){
      cout << -1 << endl;
    }
  }
}