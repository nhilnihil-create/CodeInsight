#include <bits/stdc++.h>
using namespace std;

int main(){
  int64_t X, Y, S;
  
  cin >> X >> Y;
  
  if (X % Y == 0){
    cout << -1 << endl;
  }
  else{
    S = X * (Y - 1);
    cout << S << endl;
  }
}