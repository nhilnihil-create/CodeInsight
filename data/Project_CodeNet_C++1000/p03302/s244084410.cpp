#include<bits/stdc++.h>
using namespace std;
int main(){
  int A,B;cin>>A>>B;
  if(A+B==15)puts("+");
  else if(A*B==15)puts("*");
  else puts("x");
}
