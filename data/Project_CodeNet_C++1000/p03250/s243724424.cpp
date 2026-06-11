#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c;
  cin >> a >> b >> c;
  int d=max(a,max(b,c));
  int e=min(a,min(b,c));
  int f=a+b+c-d-e;
  cout << d*10+e+f << endl;
}
 
            
            
  
