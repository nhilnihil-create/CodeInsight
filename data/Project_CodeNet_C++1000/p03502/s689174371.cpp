#include<bits/stdc++.h>
using namespace std;

int main(){
  int X; 
  cin >> X;
  
  int sum /*f(X)*/ = 0;
  int unk = X;
  for (int i=0; i<9; i++){
    sum += unk % 10;
    unk /= 10; 
  }
  
  if (X % sum == 0)
    cout << "Yes" << endl;
  else if (X % sum != 0)
    cout << "No" << endl;
}
