#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,C,X,Y;
  cin >> A >> B >> C >> X >> Y;
  int cost1,cost2,cost3;
  
  cost1=A*X+B*Y;
  if(X<=Y){
    cost2=2*C*X+B*(Y-X);
  }
  else{
    cost2=2*C*Y+A*(X-Y);
  }
    
  
  cost3=2*C*max(X,Y);
  
  cout << min({cost1,cost2,cost3}) << endl;
}