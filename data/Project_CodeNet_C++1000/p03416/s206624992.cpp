#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, D, N, sum=0;
  cin >> A >> B;
  N = B-A+1;
  
  for (int i=0; i<N; i++) {
    int a,b,c,d,e;
    a = A/10000;
    b = (A-a*10000)/1000;
    c = (A-a*10000-b*1000)/100;
    d = (A-a*10000-b*1000-c*100)/10;
    e = A-a*10000-b*1000-c*100-d*10;
    
    if ((a==e) && (b==d)) {
      sum++;
    }
    
    A++;
  }
  
  cout << sum << endl;
  
}