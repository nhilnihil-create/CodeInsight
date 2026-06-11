#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,d,e;
  cin >> a;
 b=a%2;
   c=a-b;
   c=c/10;
   d=c%2;
   e=c-d;
   e=c/10;
   e=e%2;
   
   
  cout << b+d+e << endl;
}