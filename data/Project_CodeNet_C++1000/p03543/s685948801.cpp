#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,a,b,c,d;
  cin >> N;
  a = N / 1000;
  N = N % 1000;
  b = N / 100;
  N = N % 100;
  c = N / 10;
  N = N % 10;
  d = N;
  
  if(a == b && b == c){
    cout << "Yes" << endl;
  }else if (b == c && c == d){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
    
}