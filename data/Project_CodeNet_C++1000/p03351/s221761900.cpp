#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a,b,c,d,e,f,g;
  cin >> a >> b >> c >> d;
  if(b>a){
  e = b-a;
  }
  else{
  e = a-b;
  }
  if(c>b){
  f = c-b;
  }
  else{
  f = b-c;
  }
  if (c>a){
  g = c-a;
  }
  else{
  g = a-c;
  }
  if(d>=g || (d>=e && d>=f)){
  cout << "Yes" << endl;
  }
  else{
  cout << "No" << endl;
  }
}
