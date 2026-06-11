#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, d, e, k;
  cin >> a >> b >> c >> d >>e >>k;

  bool ans=true;

  if(b-a>k) ans=false;
  if(c-a>k) ans=false;
  if(d-a>k) ans=false;
  if(e-a>k) ans=false;
  if(c-b>k) ans=false;
  if(d-b>k) ans=false;
  if(e-b>k) ans=false;
  if(d-c>k) ans=false;
  if(e-c>k) ans=false;
  if(e-d>k) ans=false;

  if(ans==true){
    cout << "Yay!" << endl;
  }
  else{
    cout << ":(" << endl;
  }
return 0;  
}