#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int a=0, b=0, c=0, d=0;
  
  cin >> a >> b >> c >> d;
  
  int dis1 = abs(a-b);
  int dis2 = abs(a-c);
  int dis3 = abs(b-c);
  
  if(dis2<=d) {
    
    cout << "Yes" << endl;
    
  } else if(dis1<=d && dis3<=d) {
    
    cout << "Yes" <<endl;
    
  } else {
    
    cout << "No" << endl;
    
  }
  
}