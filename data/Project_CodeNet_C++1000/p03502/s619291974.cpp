	
	
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  int a,b,c,d;
  a = 1;
  c = 0;
  cin >> N;
    a = a * 10;
    b = N % a;
    d = b;
    c = c + b;
   for (int i=0;i < 8;i++){
    a = a * 10;
    b = N % a;
    b = (b - d) / (a / 10);
    c = c + b; 
    d = b;
    
     }
  if (N % c == 0){
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
    
}
