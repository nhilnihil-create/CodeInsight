#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c;
  cin >> a >> b >> c;
  
  if(max(a,b)-min(a,b) == (max(a,c) -min(a,c))+(max(b,c) -min(b,c))){
    cout << "Yes" << endl;
  }
  
  else{
    cout << "No" << endl;
  }
}