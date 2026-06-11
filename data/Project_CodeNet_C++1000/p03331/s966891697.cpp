#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, a, b, c, d, e, f, p, q, r, s, t, u;
  cin >> N;
  
  int lowest = 200;
   
  for (int i = 2; i < N/2+2; i++) {
    
    a = i/100000; 
    b = (i-a*100000)/10000; 
    c = (i-a*100000-b*10000)/1000; 
    d = (i-a*100000-b*10000-c*1000)/100;
    e = (i-a*100000-b*10000-c*1000-d*100)/10;
    f = i-a*100000-b*10000-c*1000-d*100-e*10;
    
    int j = N - i;
    
    p = j/100000; 
    q = (j-p*100000)/10000; 
    r = (j-p*100000-q*10000)/1000; 
    s = (j-p*100000-q*10000-r*1000)/100;
    t = (j-p*100000-q*10000-r*1000-s*100)/10;
    u = j-p*100000-q*10000-r*1000-s*100-t*10;
    
    int sum = 0;
    sum = a+b+c+d+e+f+p+q+r+s+t+u;       
    
    if ( sum <= lowest ) {
      lowest = sum;
    }
    else {
    }
    
  }
  
  cout << lowest << endl;
    
}