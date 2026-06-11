#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a;
  int b;
  int count=0;

   
  cin >> a >>b;
  
  for (int i = a; i <=b; i++) {
 
   int c;
   int d;
   int e;
   int f;
   int g;
   g=i;
   c=g%10;
   g/=10;
   d=g%10;
   g/=100;
   e=g%10;
   g/=10;
   f=g%10;
        if(c==f&&d==e){
       count++;
   }
 
  }
  cout <<count<<endl;
}
