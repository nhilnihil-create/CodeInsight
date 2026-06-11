#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a,b,c;
  cin>>a>>b; 
  if((a+b)%2 == 1){
    c=a+b+1;
  }else{
    c=a+b;
  }
  cout<< c/2 << endl;
}