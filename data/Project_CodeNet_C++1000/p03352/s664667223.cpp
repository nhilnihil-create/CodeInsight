#include <bits/stdc++.h>
using namespace std;

int main(){
  int x;
  cin >> x;
  
  int max = 0, x2 = sqrt(x);
  for (int i=1 ; i<=x2; i++){
    for (int j=2 ; j<=x+1 ; j++){
      if (max < pow(i, j))
        max = pow(i, j);
      if (pow(i, j+1) > x)
        break;
    }
  }
  
  cout << max << endl;
}