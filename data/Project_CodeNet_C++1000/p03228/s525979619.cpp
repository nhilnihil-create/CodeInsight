#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n;
  long a,b;
  cin >> a >> b >> n;
  int count =0;
  while(1){
    if(a%2==1)
      a-=1;
    b+=a/2;
    a /= 2;
    //cout << "a " << a << " b " << b << endl;
    count++;
    if(count >= n)
      break;
    
    if(b%2==1)
      b-=1;
    a+=b/2;
    b /=2;
    //cout << "a " << a << " b " << b << endl;
    count++;
    if(count >= n)
      break;
  }
  cout << a << " " << b << endl;
}