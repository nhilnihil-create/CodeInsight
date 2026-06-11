#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, K;
  cin >> A >> B >> K;
  
  for(int i=0; i<K; i++) {
    if(i%2 ==0 && A%2 !=0) { A--; B += A/2; A /=2;}
    else if(i%2 ==0 && A%2 ==0) { B += A/2; A /=2;}
    else if(i%2 !=0 && B%2 !=0) { B--; A += B/2; B /=2;}
    else if(i%2 !=0 && B%2 ==0) { A += B/2; B /=2;}
  }
  cout << A << " " << B << endl;
}