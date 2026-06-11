#include <bits/stdc++.h>
using namespace std;

int main(){
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  
  vector<int> ans(3);
  
  ans.at(0) = X*A + Y*B;
  
  if(X >= Y){
    ans.at(1) = 2*X*C;
    ans.at(2) = 2*Y*C + (X-Y)*A;
  }
  else{
    ans.at(1) = 2*Y*C;
    ans.at(2) = 2*X*C + (Y-X)*B;
  }
  
  sort(ans.begin(), ans.end());
  
  cout << ans.at(0) << endl;
}