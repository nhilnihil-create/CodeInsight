#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)

int main(){
  vector<int> c(9);
  rep(i,9){
    cin >> c[i];
  }
  
  int a1 = 0;
  int a2,a3,b1,b2,b3;
  
  b1 = c[0];
  b2 = c[1];
  b3 = c[2];
  
  a2 = c[4]-b2;
  a3 = c[8]-b3;
  
  if(a2+b1==c[3] && a2+b3==c[5] && a3+b1==c[6] && a3+b2==c[7]) cout << "Yes" << endl;
  else cout << "No" << endl;
}
