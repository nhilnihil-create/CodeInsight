#include <bits/stdc++.h>
using namespace std;

int main() {
    
    
  int N , A , B , C = 0,D;
  cin >> A >> B;
  int a , b , c , d, e;
  N = B-A+1;
  D = A;
    for (int i = 0; i < N; i++) { 
	
      A = D;
        
      a =A%10;
      A = A/10;
      b =A%10;
      A = A/10;
      c =A%10;
      A = A/10;
      d =A%10;
      A = A/10;
      e = A%10;
      
    
	if (a == e && b == d) {
      C ++ ;
    }
      D++ ;
    }

  cout << C << endl;

}
	
