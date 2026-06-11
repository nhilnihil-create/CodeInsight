#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, d, N;
  cin >> N;
  a = N /1000;
  d = N % 1000 %100 %10;
  c = (N %1000 %100 -d) / 10 ;
  b = (N %1000 -d -c) / 100;
  
  if(a == b && a == c){
    cout << "Yes";
  }else if(b == c && c == d){
    cout << "Yes";
  }else{
    cout << "No";
  }
}
